/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:34:24 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/20 18:34:26 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**
** ---------------------------------------------------------------------------
**
*/

void		logo(t_var *x)
{
	int		len;

	x->num_obj = -1;
	while (x->objects[++x->num_obj])
		;
	// if (x->width > 47 && x->height > x->num_obj + 5)
	// {
		// printf("X terminal: %f\n", x->width);
		// printf("Y terminal: %f\n", x->height);
		// printf("%f / %f = %f\n", x->width, x->col, x->x_nums);
		ft_putstr("▒█▀▀▀ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█▀▀█ ▀▀█▀▀\n");
		ft_putstr("▒█▀▀▀ ░▒█░░ ░▀▀▀▄▄ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█░░░ ░▒█░░\n");
		ft_putstr("▒█░░░ ░▒█░░ ▒█▄▄▄█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄▄ ▒█▄▄█ ░▒█░░\n\n");
	// }
	len_obj(x->objects, -1, x);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		print_objects(t_var *x)
{
	int		row;
	int		col;
	int		current;
	int		cursor;

	cursor = 5;
	col = 0;
	current = 0;
	while (x->objects[col] && col < x->col)
	{
		ft_cursor_goto(0, cursor);
		row = col;
		while (x->objects[row] && current < x->x_nums)
		{
			if (row == x->cursor)
				mode_str("us");
			if (x->select[row] == 1)
				mode_str("so");
			ft_putstr_fd(x->objects[row], 2);
			mode_str("ue");
			mode_str("se");
			if (row + x->col < x->total)
			{
				put_space(x, x->objects[row]);
				ft_putstr_fd(" ", 2);
			}
			row = x->col + row;
			if (row > x->total)
				break ;
			if (col > x->col)
				break ;
			current++;
		}
		col++;
		cursor++;
		current = 0;
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		print_screen_se(int sig)
{
	int		col;
	int		row;
	double	p;
	double	q;
	t_var	*x;

	row = -1;
	col = 0;
	x = safe_t_var(x, 1);
	ft_clrscreen(x->y);
	ft_cursor_goto(0, 0);
	size_term(x);
	logo(x);
	len_print(0, x->objects, x);
	if (x->total > x->col)
		p = (x->col / x->largo);
	else
		p = 1;
	q = (x->largo * x->x_nums);
	printf("P: %d * %f = %f\n", x->largo, x->x_nums, q);
	printf("Y: %f <= %f && X: %f <= %f\n",p, (x->width / x->largo), q, x->width);
	if (p <= (x->width / x->largo) && q <= x->width)
		print_objects(x);
	else
		ft_putstr("Houston we have a problem!");
}
