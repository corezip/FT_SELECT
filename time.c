/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** OPTION_T
** ---------------------------------------------------------------------------
** Funcion simple con la que determinaremos que tipo de impresion es necesaria
*/

void			option_t(t_top *x, char *file, char *path)
{
	if (x->flag.l > 0 && x->flag.rr > 0)
		print_value_recu(file, path);
	else if (x->flag.l > 0 || (x->flag.l > 0 && x->flag.r > 0))
		print_value_ls(file);
	else
		ft_printf("%s\n", file);
}

/*
** COMP_MATRIX_T_R
** ---------------------------------------------------------------------------
** Esta funcion hara el cambio de lugar por comparacion de tiempo en modo
** reversivo.
*/

void			comp_matrix_t_r(t_top *x, char **matrix, char **times,
	char *path)
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
		option_t(x, matrix[x->type.j], path);
}

/*
** COMP_MATRIX_T
** ---------------------------------------------------------------------------
** Esta funcion hara el cambio de lugar por comparacion de tiempo.
*/

void			comp_matrix_t(t_top *x, char **matrix, char **times, char *path)
{
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while (times[++x->type.j] != NULL)
		{
			if ((times[x->type.j + 1] && ft_strcmp(times[x->type.j],
				times[x->type.j + 1]) == 0) && (matrix[x->type.j + 1] &&
				ft_strcmp(matrix[x->type.j], matrix[x->type.j + 1]) < 0))
			{
				ft_swapchar(&matrix[x->type.j + 1], &matrix[x->type.j]);
				x->type.flag++;
			}
			if (times[x->type.j + 1] && ft_strcmp(times[x->type.j],
				times[x->type.j + 1]) < 0)
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
		option_t(x, matrix[x->type.j], path);
}

/*
** FT_CATCHING_TIME_R
** ---------------------------------------------------------------------------
** En esta funcion obtendremos el tiempo de los files para carpetas introduci-
** das por argumentos o cuando sea de manera recursiva.
*/

char			**ft_catching_time_r(int size, t_top *x,
	char **files, char *path)
{
	struct stat		filestat;
	int				i;
	char			**matrix;

	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (files[++i] != NULL)
	{
		if (ft_strcmp(path, ".") == 0)
		{
			x->type.tmp2 = ft_strjoin("./", files[i]);
			x->type.tmp = ft_strjoin(x->type.tmp2, "/");
			x->type.tmp3 = ft_strdup(x->type.tmp);
		}
		else
		{
			x->type.tmp = ft_strjoin(path, "/");
			x->type.tmp3 = ft_strjoin(x->type.tmp, files[i]);
		}
		lstat(x->type.tmp3, &filestat);
		matrix[i] = ft_strdup(ft_itoa(filestat.st_ctime));
	}
	matrix[i] = NULL;
	x->type.j = -1;
	return (matrix);
}

/*
** FT_CATCHING_TIME
** ---------------------------------------------------------------------------
** En esta funcion se obtendra el tiempo de una carpeta raiz o archivo.
*/

char			**ft_catching_time(int size, t_top *x,
	char **files, char *path)
{
	struct stat		filestat;
	int				i;
	char			**matrix;

	if (x->flag.rec > 1)
	{
		x->type.j = -1;
		return (ft_catching_time_r(size, x, files,
			path));
	}
	matrix = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (files[i] != NULL)
	{
		lstat(files[i], &filestat);
		matrix[i] = ft_strdup(ft_itoa(filestat.st_ctime));
		i++;
	}
	matrix[i] = NULL;
	x->flag.rec += 1;
	x->type.j = -1;
	return (matrix);
}
