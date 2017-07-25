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
	if (x->width > 47 && x->height > x->num_obj + 5)
	{
		ft_putstr("▒█▀▀▀ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█▀▀█ ▀▀█▀▀\n");
		ft_putstr("▒█▀▀▀ ░▒█░░ ░▀▀▀▄▄ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█░░░ ░▒█░░\n");
		ft_putstr("▒█░░░ ░▒█░░ ▒█▄▄▄█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄▄ ▒█▄▄█ ░▒█░░\n\n\n");
	}
	len_obj(x->objects, -1, x);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void		print_objects(t_var *x, int i)
{
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

void		print_screen_se(int sig)
{
	int		col;
	int		row;
	t_var	*x;

	row = -1;
	col = 0;
	x = safe_t_var(x, 1);
	ft_clrscreen(x->y);
	ft_cursor_goto(0, 0);
	size_term(x);
	logo(x);
	if (x->largo < x->width)
		print_objects(x, -1);
	else
		ft_putstr("Houston we have a problem");
}
