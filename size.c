/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:05:10 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/20 18:05:11 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** SIZE_TERM
** ---------------------------------------------------------------------------
** Funcion que utiliza winzise para conocer el tamaño de X y Y de la terminal.
*/

void				size_term(t_var *x)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	x->width = win.ws_col;
	x->height = win.ws_row;
	x->col = x->height - 5;
	x->x_nums = (x->width / x->col);
}

/*
** LEN_OBJ
** ---------------------------------------------------------------------------
** Funcion que obtiene el largo del argumento mas largo.
*/

void				len_obj(char **matrix, int i, t_var *x)
{
	int				tmp;

	x->largo = 0;
	tmp = 0;
	while (matrix[++i])
	{
		tmp = ft_strlen(matrix[i]);
		if (tmp > x->largo)
			x->largo = tmp;
	}
}

/*
** MAX_WIDTH
** ---------------------------------------------------------------------------
** Funcion que obtiene el largo del argumento mas largo.
*/

int					max_width(char **mtx)
{
	int				max;
	int				i;
	int				tmp;

	max = 0;
	i = -1;
	while (mtx[++i])
	{
		if (max < (tmp = (int)ft_strlen(mtx[i])))
			max = tmp;
	}
	return (max);
}
