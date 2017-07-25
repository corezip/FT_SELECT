/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:02:28 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/20 18:02:31 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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

void		del_opt(t_var *x)
{
	int		i;

	i = -1;
	while (x->select[++i] == 0)
		;
	if (x->select[i] == 1)
		{
			x->select[x->cursor] = 0;
			x->total_selected -= 1;
		}
	else
	{
		ft_clrscreen(x->x);
		exit(0);
	}
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
	exit(EXIT_SUCCESS);
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
			del_opt(x);
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
		(refresh) ? print_screen_se(1) : 0;
		key = 0;
	}
}
