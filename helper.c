/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:26:53 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/25 16:26:55 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**
** ---------------------------------------------------------------------------
**
*/

void		suspend_term(int signum)
{
	t_var	*x;
	char	tmp[3];

	signum++;
	x = safe_t_var(x, 1);
	ft_clrscreen(x->y);
	x->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, &x->term);
	mode_str("te");
	mode_str("ve");
	signal(SIGTSTP, SIG_DFL);
	tmp[0] = x->term.c_cc[VSUSP];
	tmp[1] = '\n';
	tmp[2] = '\0';
	ioctl(0, TIOCSTI, &tmp);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		continue_term(int signum)
{
	t_var	*x;

	signum++;
	x = safe_t_var(x, 1);
	set_stage(x);
	set_signals();
	init_var(x, x->ac, x->ar);
	safe_t_var(x, 0);
	print_screen_se(1);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		safe_exit(int singnum)
{
	t_var	*x;

	x = safe_t_var(x, 1);
	ft_memdel((void**)&x->select);
	ft_clrscreen(x->y);
	mode_str("te");
	mode_str("ve");
	exit(3);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		put_space(t_var *x, char *str)
{
	int tmp;

	tmp = ft_strlen(str);
	while (x->len > tmp)
	{
		ft_putstr_fd(" ", 2);
		tmp++;
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

int			len_print(int len, char **obj, t_var *x)
{
	int		i;
	double	tmp;

	x->col = x->height - 5;
	x->x_nums = x->width / x->largo;
	i = x->x_nums;
	tmp = x->x_nums - i;
	if (tmp > 0.001)
		x->x_nums = (x->x_nums - tmp) + 1;
	num_obj(x);
	return (0);
}
