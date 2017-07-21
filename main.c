/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:40:53 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/11 15:40:54 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**
** ---------------------------------------------------------------------------
**
*/

void			init_var(t_var *x, int ac, char **ar)
{
	x->len = 0;
	x->full = 0;
	x->cursor = 0;
	x->total_selected = 0;
	x->arg_height = ac - 1;
	x->objects = ar + 1;
	x->arg_width = max_width(x->objects);
	x->select = (int *)ft_memalloc(sizeof(int) * x->arg_height);
}

/*
**
** ---------------------------------------------------------------------------
**
*/
int				set_stage(t_var *x)
{
	if (tgetent(x->buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &x->term);
	x->term.c_lflag &= ~(ICANON);
	x->term.c_lflag &= ~(ECHO);
	x->term.c_cc[VMIN] = 1;
	x->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &x->term);
	x->y = tgetnum("li");
	x->x = tgetnum("co");
	mode_str("ti");
	mode_str("ve");
	return (1);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void	set_signals(void)
{
	// signal(SIGHUP, safe_exit);
	// signal(SIGINT, safe_exit);
	// signal(SIGQUIT, safe_exit);
	// signal(SIGILL, safe_exit);
	// signal(SIGTRAP, safe_exit);
	// signal(SIGABRT, safe_exit);
	// signal(SIGEMT, safe_exit);
	// signal(SIGFPE, safe_exit);
	// signal(SIGBUS, safe_exit);
	// signal(SIGSEGV, safe_exit);
	// signal(SIGSYS, safe_exit);
	// signal(SIGPIPE, safe_exit);
	// signal(SIGALRM, safe_exit);
	// signal(SIGTERM, safe_exit);
	// signal(SIGTTIN, safe_exit);
	// signal(SIGTTOU, safe_exit);
	// signal(SIGXCPU, safe_exit);
	// signal(SIGXFSZ, safe_exit);
	// signal(SIGVTALRM, safe_exit);
	// signal(SIGPROF, safe_exit);
	// signal(SIGUSR1, safe_exit);
	// signal(SIGUSR2, safe_exit);
	// signal(SIGTSTP, suspend_term);
	// signal(SIGCONT, continue_term);
	signal(SIGWINCH, print_screen_se);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

int				main(int ac, char **ar)
{
	t_var		*x;

	if (ac < 2)
		printf("no arguments!!\n");
	else
	{
		x = saved_env(x);
		if (!set_stage(x))
			printf("Vamos mal\n");
		set_signals();
		init_var(x, ac, ar);
		safe_t_var(x, 0);
		print_screen_se(1);
		read_key(x);
	}
	return (0);
}
