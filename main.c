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

t_var	*saved_env(t_var *env)
{
	static t_var *setenv;

	if (env)
	{
		setenv = env;
		return (setenv);
	}
	else
		return (setenv);
}


/*
**
** ---------------------------------------------------------------------------
**
*/

void			size_term(t_var *x)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	x->width = win.ws_col;
	x->height = win.ws_row;
	printf("X terminal: %d\n", x->width);
	printf("Y terminal: %d\n", x->height);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void	ft_cursor_goto(int x, int y)
{
	char *str1;
	char *str2;

	if ((str1 = tgetstr("cm", NULL)) != NULL)
	{
		if ((str2 = tgoto(str1, x, y)) != NULL)
			ft_putstr_fd(str2, 2);
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void			mode_str(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(tgetstr(str, NULL), 2);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void	ft_clrscreen(int rows)
{
	while (--rows >= 0)
	{
		ft_cursor_goto(0, rows);
		mode_str("dl");
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		logo(t_var *x)
{
	x->num_obj = -1;
	while (x->objects[++x->num_obj]);
	if (x->width > 47 && x->height > x->num_obj + 5)
	{
		ft_putstr("▒█▀▀▀ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█▀▀█ ▀▀█▀▀\n");
		ft_putstr("▒█▀▀▀ ░▒█░░ ░▀▀▀▄▄ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█░░░ ░▒█░░\n");
		ft_putstr("▒█░░░ ░▒█░░ ▒█▄▄▄█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄▄ ▒█▄▄█ ░▒█░░\n\n\n");
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		print_screen(t_var *x)
{
	int		i;
	int		col;
	int		row;

	row = -1;
	col = 0;
	i = -1;
	ft_clrscreen(x->y);
	ft_cursor_goto(0, 0);
	size_term(x);
	logo(x);
	while (x->objects[++i])
	{
		if (i == x->cursor)
			mode_str("us");
		if (x->select[i] == 1)
			mode_str("so");
		ft_putstr_fd(x->objects[i], 2);
		mode_str("ue");
		mode_str("se");
		write(1, "\n", 1);
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

int			max_width(char **mtx)
{
	int		max;
	int		i;
	int		tmp;

	max = 0;
	i = -1;
	while (mtx[++i])
	{
		if (max < (tmp = (int)ft_strlen(mtx[i])))
			max = tmp;
	}
	return (max);
}

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

void		key_up_down(t_var *x, long key)
{
	if (key == KEY_ABJ)
	{
		if (x->cursor == (x->arg_height - 1))
			x->cursor = 0;
		else if (x->cursor < x->arg_height)
			x->cursor += 1;
	}
	else if (key == KEY_ARR)
	{
		if (x->cursor == 0)
			x->cursor = (x->arg_height - 1);
		else
			x->cursor -= 1;
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		key_space(t_var *x, long key)
{
	if (x->select[x->cursor] == 0)
		{
			x->select[x->cursor] = 1;
			x->total_selected += 1;
		}
	else
	{
		x->select[x->cursor] = 0;
		x->total_selected -= 1;
	}
	key_up_down(x, KEY_ABJ);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		return_values(t_var *x)
{
	int		i;
	int		cont;

	cont = 0;
	i = -1;
	ft_clrscreen(x->x);
	mode_str("ve");
	while (x->objects[++i])
	{
		if (x->select[i] == 1)
		{
			ft_printfcolor("%s", x->objects[i], 94);
			cont += 1;
			if (cont != x->total_selected)
				ft_putchar(' ');
		}
	}
	ft_memdel((void**)&x->select);
	exit (EXIT_SUCCESS);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		read_key(t_var *x)
{
	long	key;
	int		refresh;

	key = 0;
	while ((read(0, &key, 8)) != 0)
	{
		refresh = 1;
		if (key == KEY_BSP || key == KEY_DEL)
			printf("del\n");
		else if (key == KEY_ARR || key == KEY_ABJ ||
				key == KEY_IZQ || key == KEY_DER)
			key_up_down(x, key);
		else if (key == KEY_SPC)
			key_space(x, key);
		else if (key == KEY_DAR)
			return_values(x);
		else if (key == KEY_STAR || key == KEY_MINUS)
			printf("minus\n");
		else if (key == KEY_ESC)
			exit(0);
		else
			refresh = 0;
		(refresh) ? print_screen(x) : 0;
		key = 0;
	}
}

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
	signal(SIGWINCH, print_screen);
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
		x = (t_var*)malloc(sizeof(t_var));
		if (!set_stage(x))
			printf("Vamos mal\n");
		set_signals();
		init_var(x, ac, ar);
		// while (1)
			print_screen(x);
		read_key(x);
	}
	return (0);
}
