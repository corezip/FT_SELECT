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
** LOGO
** ---------------------------------------------------------------------------
** Esta funcion imprime el logo superior del programa para darle un poco de
** estetica, donde se comprueba si tiene espacio para imprimirlo.
** En caso de no haber espacio, no se imprime y la impresion de las columnas
** se recorren hacia la parte superior de la terminal.
*/

void		logo(t_var *x)
{
	char	*z;

	x->num_obj = -1;
	while (x->objects[++x->num_obj])
		;
	if (x->width > 47 && x->height > 5)
	{
		ft_putstr_fd("▒█▀▀▀ ▀▀█▀▀ ▒█▀▀▀█ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█▀▀█ ▀▀█▀▀\n", 2);
		ft_putstr_fd("▒█▀▀▀ ░▒█░░ ░▀▀▀▄▄ ▒█▀▀▀ ▒█░░░ ▒█▀▀▀ ▒█░░░ ░▒█░░\n", 2);
		ft_putstr_fd("▒█░░░ ░▒█░░ ▒█▄▄▄█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄▄ ▒█▄▄█ ░▒█░░\n", 2);
		z = ft_itoa(x->total_selected);
		ft_putstr_fd("Total Selected: ", 2);
		ft_putstr_fd(z, 2);
		ft_memdel((void**)&z);
		ft_putstr_fd("\n", 2);
		x->z = 5;
	}
	else
		x->z = 0;
	len_obj(x->objects, -1, x);
}

/*
** PRINT_OBJECTS_2
** ---------------------------------------------------------------------------
**  Esta funcion hace la comprobacion de que argumentos, si estan
** seleccionados o no, para asi imprimir el argumento y despues imprimir los
** espacios faltantes para que sea del mismo tamaño del argumento mas largo.
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
** PRINT_OBJECTS
** ---------------------------------------------------------------------------
** Esta funcion hace los loop y el control de los argumentos, de el tamaño de
** la terminal, hace la comprobacion de la existencia de argumentos para
** proceder a la funcion que se encarga de la impresion.
*/

void		print_objects(t_var *x)
{
	int		row;
	int		col;
	int		current;
	int		cursor;

	cursor = x->z;
	col = 0;
	current = 0;
	while (x->objects[col] && col < x->col)
	{
		ft_cursor_goto(0, cursor);
		row = col;
		while (x->objects[row] && current <= (x->x_nums - 1))
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
** PRINT_SCREEN_SE
** ---------------------------------------------------------------------------
** Esta funcion es primer paso para la impresion en la nueva terminal, dando
** el inicio a todos los pasos para el control e impresion de los argumentos.
*/

void		print_screen_se(int sig)
{
	int		col;
	int		row;
	double	p;
	t_var	*x;

	x = NULL;
	row = -1;
	col = 0;
	sig = 0;
	x = safe_t_var(x, 1);
	x->y = tgetnum("li");
	ft_clrscreen(x->y);
	ft_cursor_goto(0, 0);
	size_term(x);
	logo(x);
	len_print(x);
	if (x->total > x->col)
		p = (x->col / x->largo);
	else
		p = 1;
	if (p <= (x->width / x->largo) && (x->total / x->col) <= (x->x_nums - 1))
		print_objects(x);
	else
		ft_putstr("Houston, We have a problem!");
}
