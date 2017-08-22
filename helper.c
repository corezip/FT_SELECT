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
** SUSPEND_TERM
** ---------------------------------------------------------------------------
** Esta funcion esta dedicada a finalizar de manera segura todo el ft_select
** sin dejar rastros de el.
*/

void		suspend_term(int signum)
{
	t_var	*x;
	char	tmp[3];

	signum++;
	x = NULL;
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
** CONTINUE_TERM
** ---------------------------------------------------------------------------
** En esta Funcion recuperaremos todos los datos y vista de la terminal que
** que previamente se habian guardado.
*/

void		continue_term(int signum)
{
	t_var	*x;

	signum++;
	x = NULL;
	x = safe_t_var(x, 1);
	set_stage(x);
	set_signals();
	print_screen_se(1);
}

/*
** SAFE_EXIT
** ---------------------------------------------------------------------------
** Guarda la vista y datos de la terminal para poder recuperarlos mas adelate
** de asi ser necesario.
*/

void		safe_exit(int singnum)
{
	t_var	*x;

	x = NULL;
	x = safe_t_var(x, 1);
	ft_memdel((void**)&x->select);
	ft_clrscreen(x->y);
	mode_str("te");
	mode_str("ve");
	singnum = 0;
	exit(3);
}

/*
** PUT_SPACE
** ---------------------------------------------------------------------------
** Imprime los espacios que hacen falta en el argumento para tener alineadas
** las columnas.
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
** LEN_PRINT
** ---------------------------------------------------------------------------
** Esta funcion hace las matematicas para obtener el numero de columnas a
** imprimir, tomando en cuenta el largo del objecto mas largo.
*/

int			len_print(t_var *x)
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
