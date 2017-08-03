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
	if (x->width > 47 && x->height > 5)
	{
		ft_putstr("▒█▀▀▀ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█▀▀█ ▀▀█▀▀\n");
		ft_putstr("▒█▀▀▀ ░▒█░░ ░▀▀▀▄▄ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█░░░ ░▒█░░\n");
		ft_putstr("▒█░░░ ░▒█░░ ▒█▄▄▄█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄▄ ▒█▄▄█ ░▒█░░\n\n");
	}
	len_obj(x->objects, -1, x);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

int			print_objects_2(t_var *x, int *row, int *col)
{
	if (*row == x->cursor)
		mode_str("us");
	if (x->select[*row] == 1)
		mode_str("so");
	ft_putstr_fd(x->objects[*row], 2);
	mode_str("ue");
	mode_str("se");
	if (*row + x->col < x->total)
	{
		put_space(x, x->objects[*row]);
		ft_putstr_fd(" ", 2);
	}
	*row = x->col + *row;
	if (*row > x->total)
		return (0);
	if (*col > x->col)
		return (0);
	return (1);
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
		while (x->objects[row] && current < (x->width / x->col))
		{
			if (print_objects_2(x, &row, &col) == 0)
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
	if (p <= (x->width / x->largo) && (x->total / x->col) <= (x->x_nums - 1))
		print_objects(x);
	else
		ft_putstr("Houston we have a problem!");
}
