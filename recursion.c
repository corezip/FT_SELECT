/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** COMP_MATRIX_R(reverse)
** ---------------------------------------------------------------------------
** Esta funcion hace impresion de los nombres sin mas informacion pero de
** con los nombres en orden ASCII(Z - A).
*/

void			comp_matrix_r(t_top *x, char **matrix)
{
	x->type.flag = 1;
	x->type.j = 0;
	if (x->flag.r >= 1)
		recursion_comp_rev(x, matrix);
	else if (x->flag.error == 0)
	{
		while (x->type.flag != 0)
		{
			x->type.flag = 0;
			while (matrix[x->type.j])
			{
				if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
					matrix[x->type.j + 1]) > 0)
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
			ft_printf("%s\n", matrix[x->type.j]);
	}
}

/*
** COMP_MATRIX
** ---------------------------------------------------------------------------
** esta funcion solo hace la distribucion de la opcion indicada para la
** resolucion de programa.
*/

void			comp_matrix(t_top *x, char **matrix, char *path)
{
	x->type.flag = 1;
	x->type.j = 0;
	if (x->flag.r >= 1)
		comp_rev(x, matrix, path);
	else
		comp_normal(x, matrix, path);
}

/*
** RECURTION_MEXA_T
** ---------------------------------------------------------------------------
** Funcion que hara el la recursividad exclusiva para la flag "t" dando las
** opciones especiales que lleva esa flag.
*/

void			remove_line(t_top *x, char **matrix, char **matrix_time,
	char *path)
{
	x->type.j = -1;
	if (x->flag.r > 0)
		comp_matrix_t_r(x, matrix, matrix_time, path);
	else
		comp_matrix_t(x, matrix, matrix_time, path);
}

void			recurtion_mexa_t(char *path, t_top *x, int i)
{
	struct stat	filestat;
	char		**matrix;
	char		*tmp;
	char		**matrix_time;

	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	matrix_time = ft_catching_time(x->type.i, x, matrix, path);
	remove_line(x, matrix, matrix_time, path);
	while (matrix[++i] != NULL)
	{
		tmp = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp, matrix[i]);
		lstat(tmp, &filestat);
		if (((S_ISDIR(filestat.st_mode) && ft_strcmp(matrix[i], "."))) &&
			((S_ISDIR(filestat.st_mode) && ft_strcmp(matrix[i], "..")))
			&& x->flag.rr > 0)
		{
			matrix[i] = ft_strdup(tmp);
			ft_printf("\n%s\n", matrix[i]);
			x->type.flag = 1;
			x->type.j = -1;
			recurtion_mexa_t(matrix[i], x, -1);
		}
	}
}

/*
** RECURTION_MEXA
** ---------------------------------------------------------------------------
** Este funcion es el motor de la -R o de los archivos introduccidos por
** argumento tambien checa que tipo de impresion debe llevar y los envia por
** esas funciones. Esta funcion hace la union del path con la carpeta a la
** que se debe acceder.
** linea 103: ft_memdel((void**)&tmp);
** si agregamos la linea 103 en la flag -R tendra un error al freesear la
** valriable temporal.
*/

void			recurtion_mexa(char *path, t_top *x, int i)
{
	char **matrix;

	matrix = safe_recurtion(x, path);
	while (matrix[++i] != '\0')
	{
		if (x->flag.error == 1)
		{
			x->flag.error = 0;
			return ;
		}
		x->dir.tmp = ft_strjoin(path, "/");
		x->dir.tmp = ft_strjoin(x->dir.tmp, matrix[i]);
		lstat(x->dir.tmp, &x->dir.filestat);
		if (((S_ISDIR(x->dir.filestat.st_mode) && ft_strcmp(matrix[i],
			"."))) && ((S_ISDIR(x->dir.filestat.st_mode) &&
			ft_strcmp(matrix[i], ".."))) && x->flag.rr > 0)
		{
			matrix[i] = ft_strdup(x->dir.tmp);
			ft_printf("\n%s\n", matrix[i]);
			recurtion_mexa(matrix[i], x, -1);
		}
	}
}
