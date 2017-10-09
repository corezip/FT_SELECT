/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** PRINT_BASIC_T_R
** ---------------------------------------------------------------------------
** Esta funcion hara el acomodado de la flag "t" y hara la impresion del
** nombre sin mas atributos de modo reversivo.
*/

void			print_basic_t_r(t_top *x, char **matrix, char **times)
{
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while (times[++x->type.j] != NULL)
		{
			if ((times[x->type.j + 1] && ft_strcmp(times[x->type.j],
				times[x->type.j + 1]) == 0) && (matrix[x->type.j + 1] &&
				ft_strcmp(matrix[x->type.j], matrix[x->type.j + 1]) > 0))
			{
				ft_swapchar(&matrix[x->type.j + 1], &matrix[x->type.j]);
				x->type.flag++;
			}
			if (times[x->type.j + 1] && ft_strcmp(times[x->type.j],
				times[x->type.j + 1]) > 0)
			{
				ft_swapchar(&times[x->type.j], &times[x->type.j + 1]);
				ft_swapchar(&matrix[x->type.j], &matrix[x->type.j + 1]);
				x->type.flag++;
			}
		}
		x->type.j = -1;
	}
	x->type.j = -1;
	while (matrix[++x->type.j] != NULL)
		print_basic_color(matrix[x->type.j]);
}

/*
** FT_LS_T
** ---------------------------------------------------------------------------
** Esta funcion hara las funciones basicas de recuperacion de datos, para
** despues mandarlo a la funcion donde se hara su organizacion por fecha.
*/

void			ft_ls_t(t_top *x, char *path)
{
	char		**matrix;
	char		**matrix_time;

	if (security_path(path) == 0)
		return ;
	x->type.flag = 1;
	x->type.j = -1;
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	if (x->flag.rr > 1)
		matrix_time = ft_catching_time_r(x->type.i, x, matrix, path);
	else
		matrix_time = ft_catching_time(x->type.i, x, matrix, path);
	x->type.j = -1;
	if (x->flag.rr >= 1)
		recurtion_mexa_t(path, x, -1);
	else if (x->flag.l >= 1 && x->flag.r == 0)
		comp_matrix_t(x, matrix, matrix_time, path);
	else if (x->flag.l >= 1 && x->flag.r >= 1)
		comp_matrix_t_r(x, matrix, matrix_time, path);
	else if (x->flag.r > 0)
		print_basic_t_r(x, matrix, matrix_time);
	else
		print_basic_t(x, matrix, matrix_time);
}

/*
** PRINT_r
** ---------------------------------------------------------------------------
** Esta funcion recibe una direccion donde creara una matriz con los que
** obtendra  los nombres de los archivos desacomodados, despues acomodara en
** orden de ASCII  pero en reversa (Z - A). E imprimira la matriz con los
** nombres de los archivos.
*/

void			print_r(t_top *x, char *path)
{
	char		**matrix;

	x->type.flag = 1;
	x->type.j = 0;
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while (matrix[x->type.j] != NULL)
		{
			if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
					matrix[x->type.j + 1]) < 0)
			{
				ft_swapchar(&matrix[x->type.j], &matrix[x->type.j + 1]);
				x->type.flag++;
			}
			x->type.j++;
		}
		x->type.j = 0;
	}
	x->type.j = -1;
	while (matrix[++x->type.j] != NULL)
		print_basic_color(matrix[x->type.j]);
}

/*
** LS_MENU
** ---------------------------------------------------------------------------
** Esta funcion es solo posible acceder si alguno de los argumentos son y solo
** son  -l -r -a -R -t.
** Esta funcion es de las mas importantes, aqui sabremos que rumbo va a tomar
** el programa, y todo sera bajo el valor que contengan las flags, si el valor
** de cada
** flag es mayor a 1, sera posible entrar a los if que estan acomndados de
** manera en que la estructura para la impresion sea correcta.
*/

void			ls_menu(t_top *x, char *path)
{
	char		**matrix;

	matrix = NULL;
	if (security_path(path) == 0)
		return ;
	if (x->flag.aa > 0 && x->flag.a == 0)
		only_dot(x, path);
	else if (x->flag.f > 0)
		no_sort(x, path);
	else if (x->flag.t >= 1)
		ft_ls_t(x, path);
	else if (x->flag.rr >= 1)
		recurtion_mexa(path, x, -1);
	else if (x->flag.a >= 1 && x->flag.l <= 0)
		print_basic(x, path);
	else if (x->flag.r >= 1 && x->flag.l <= 0)
		print_r(x, path);
	else
		print_l(x, path, matrix);
}

/*
** MAIN
** ---------------------------------------------------------------------------
** Iniciamos en Main donde nos dirigiremos depende del numero de argumentos
** que introducen.
** En caso de tener 2 argumentos(tomando en cuanta el nombre del archivo)
** entraremos a la funcion donde veremos si los argumentos son -l -r -R
** -a -t o en conjunto -lRar o combinaciones posibles.
** En caso de que el argumento no tenga "-" el argumento se tomara como
** referencia a un archivo.
** En caso de que se introduzca un argumento que comience en "-" y no sea
** uno dentro de los reconocidos de imprimira el mensaje de illegal option.
*/

int				main(int argc, char **argv)
{
	t_top		*x;

	x = (t_top*)malloc(sizeof(t_top));
	flag_zero(x);
	if (argc >= 1)
	{
		if (argc == 1)
			print_basic(x, ".");
		else if (argc >= 2)
		{
			start_flag(argv, x);
			if (flag_on(x) && x->flag.file <= 0)
				ls_menu(x, ".");
			else if (x->flag.file == 0)
				ft_printf("ft_ls: illegal option -- %c\nusage: ft_ls"
					" [-ARaflrt] [file ...]\n", argv[1][1]);
		}
	}
	ft_memdel((void**)&x);
	return (1);
}
