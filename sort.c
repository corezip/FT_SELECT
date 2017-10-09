/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** SECURITY_PATH
** ---------------------------------------------------------------------------
** Esta funcion comprueba los accesos a los files o carpetas para evitar
** errores de permisos.
*/

int				security_path(char *path)
{
	FILE		*fp;

	fp = fopen(path, "r");
	if (fp == NULL)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return (0);
	}
	return (1);
}

/*
** COMP_MATRIX_R(reverse)
** ---------------------------------------------------------------------------
** Esta funcion hace impresion de los nombres sin mas informacion pero de
** con los nombres en "reversa" (Z - A).
*/

void			recursion_comp_rev(t_top *x, char **matrix)
{
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
		ft_printf("%s\n", matrix[x->type.j]);
}

/*
** COMP_REV
** ---------------------------------------------------------------------------
** Funcion destinada a ordenar la matrix en orden ASCII pero en "reversa"
** tambien hace la eleccion de que tipo de impresion va a tener si recursivo o
** impresion con todos los datos.
*/

void			comp_rev(t_top *x, char **matrix, char *path)
{
	matrix = matrix_sort_reverse(x, matrix);
	x->type.j = -1;
	while (matrix[++x->type.j] != NULL)
	{
		if (x->flag.rr >= 1 || x->flag.file > 0)
			print_value_recu(matrix[x->type.j], path);
		else
			print_value_ls(matrix[x->type.j]);
	}
}

/*
** COMP_NORMAL
** ---------------------------------------------------------------------------
** Funcion destinada a ordenar la matrix en orden ASCII tambien hace la
** eleccion  de que tipo de impresion va a tener si recursivo o impresion
** con todos los datos.
*/

void			comp_normal(t_top *x, char **matrix, char *path)
{
	matrix = matrix_sort(x, matrix);
	x->type.j = -1;
	while (matrix[++x->type.j] != NULL)
	{
		if (x->flag.rr >= 1 || x->flag.file > 0)
			print_value_recu(matrix[x->type.j], path);
		else
			print_value_ls(matrix[x->type.j]);
	}
}

/*
** PRINT_L
** ---------------------------------------------------------------------------
** Esta funcion solo imprimira los datos de los archivo recreando la funcion
** del comando "ls -l"
*/

void			print_l(t_top *x, char *path, char **matrix)
{
	print_blocks_size(x, path);
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	comp_matrix(x, matrix, path);
}
