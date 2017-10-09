/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
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

void				no_sort(t_top *x, char *path)
{
	char			**matrix;
	int				z;

	z = -1;
	x->flag.a = 1;
	x->flag.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->flag.i, x, path);
	while (matrix[++z])
	{
		if (x->flag.l > 0)
			print_value_ls(matrix[z]);
		else
			print_basic_color(matrix[z]);
	}
}

void				only_dot(t_top *x, char *path)
{
	char			**matrix;

	x->flag.a = 1;
	x->flag.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->flag.i, x, path);
	x->flag.i = -1;
	matrix = matrix_sort(x, matrix);
	while (matrix[++x->flag.i])
	{
		if (x->flag.l == 0)
		{
			if (ft_strcmp(matrix[x->flag.i], ".") != 0 &&
				ft_strcmp(matrix[x->flag.i], "..") != 0)
				print_basic_color(matrix[x->flag.i]);
		}
		else
		{
			if (ft_strcmp(matrix[x->flag.i], ".") != 0 &&
				ft_strcmp(matrix[x->flag.i], "..") != 0)
				print_value_ls(matrix[x->flag.i]);
		}
	}
}

int					safe_lines(DIR **pdir, char *path, t_top *x)
{
	x->dir.i = 0;
	if (!(*pdir = opendir(path)))
	{
		x->flag.error = 1;
		return (1);
	}
	return (0);
}

char				**safe_recurtion(t_top *x, char *path)
{
	char **matrix;

	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	if (x->flag.l >= 1 || (x->flag.file >= 1 && x->flag.l >= 1))
		comp_matrix(x, matrix, path);
	else
		comp_matrix_r(x, matrix);
	return (matrix);
}

void				print_basic_color(char *file)
{
	struct stat		filestat;

	lstat(file, &filestat);
	if (!S_ISDIR(filestat.st_mode))
		ft_printf("%s\n", file);
	else
		ft_printfcolor("%s\n", file, 34);
}
