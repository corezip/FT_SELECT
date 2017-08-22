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
** KEY_UP_DOWN
** ---------------------------------------------------------------------------
** Esta funcion es la que controla los movimientos entre los argumentos y las
** teclas de arriba, abajo, derecha e izquierda; para poder navegar entre
** la interfaz.
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
	else if (key == KEY_IZQ)
	{
		if (x->cursor - x->col >= 0)
			x->cursor -= x->col;
	}
	else if (key == KEY_DER)
	{
		if (x->cursor + x->col < x->total)
			x->cursor += x->col;
	}
	extra_key(x, key);
}

/*
** KEY_SPACE
** ---------------------------------------------------------------------------
** Con esta funcion hacemos la activacion o desactivacion del algumento para
** su marcado o desmarcado, cambiando el valor de la matriz select a 0 para
** descativarlo, o 1 para activarlo.
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
	key = 0;
	key_up_down(x, KEY_ABJ);
}

/*
** DEL_OPT
** ---------------------------------------------------------------------------
** Esta funcion hara posible eliminar de la pantalla los argumentos que sean
** seleccionados para su eliminacion, pero lo unico que hace esta funcion es
** mover ese argumento al final de la matriz.
*/

void		del_opt(t_var *x)
{
	int		i;

	num_obj(x);
	i = 0;
	if (x->select[x->cursor] == 1)
		x->total_selected -= 1;
	ft_arr_remove_nth(x->cursor, x->objects, sizeof(char *), x->total);
	ft_arr_remove_nth(x->cursor, x->select, sizeof(int), x->total);
	x->arg_height -= 1;
	x->cursor -= 1;
	if (x->arg_height == 0)
		return_values(x);
	key_up_down(x, KEY_ABJ);
}

/*
** RETURN_VALUES
** ---------------------------------------------------------------------------
** Esta funcion regresara la vista de la terminal original antes de iniciar el
** ft_select e imprimira los argumentos seleccionados.
*/

void		return_values(t_var *x)
{
	int		i;
	int		cont;

	cont = 0;
	i = -1;
	ft_clrscreen(x->y);
	mode_str("te");
	mode_str("ve");
	while (x->objects[++i])
	{
		if (x->select[i] == 1)
		{
			ft_putstr(x->objects[i]);
			cont += 1;
			if (cont != x->total_selected)
				ft_putchar(' ');
		}
	}
	ft_memdel((void**)&x->select);
	exit(EXIT_SUCCESS);
}

/*
** READ_KEY
** ---------------------------------------------------------------------------
** Esta funcion renocera el valor de la tecla que estamos recibiendo y la
** compara con las que ya tenemos definidas en el header.
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
			ft_printfcolor("minus\n");
		else if (key == KEY_ESC)
			safe_exit(0);
		else
			refresh = 0;
		(refresh) ? print_screen_se(1) : 0;
		key = 0;
	}
}
