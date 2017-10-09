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
** FLAG_ON
** ---------------------------------------------------------------------------
** Esta funcion solo revisara si alguna flag esta encendida para dar acceso a
** LS_MENU
*/

int			flag_on(t_top *x)
{
	x->type.size = 0;
	x->type.flag = 1;
	x->type.j = 0;
	if (x->flag.l > 0 || x->flag.f > 0)
		return (1);
	else if (x->flag.rr > 0)
		return (1);
	else if (x->flag.a > 0 || x->flag.aa > 0)
		return (1);
	else if (x->flag.r > 0)
		return (1);
	else if (x->flag.t > 0)
		return (1);
	return (0);
}

/*
** GET_FILE2
** ---------------------------------------------------------------------------
** Extencion de la funcion get_file.
** Esta funcion simplemente obtiene el nombre de la file o directorio que
** vamos a analizar junto con las flags en caso de tener activa alguna.
*/

void		get_file2(char *file, t_top *x)
{
	struct stat filestat;

	stat(file, &filestat);
	if (S_ISDIR(filestat.st_mode))
	{
		recurtion_mexa(file, x, 0);
	}
	else
		print_value_ls(file);
}

/*
** GET_FILE
** ---------------------------------------------------------------------------
** Esta funcion simplemente obtiene el nombre de la file o directorio que
** vamos a analizar junto con las flags en caso de tener activa alguna.
*/

void		get_file(char *file, t_top *x)
{
	struct stat filestat;

	x->flag.file = 1;
	if (lstat(file, &filestat) < 0)
	{
		ft_printf("ls: %s: %s\n", file, strerror(errno));
		return ;
	}
	if (get_file_error(filestat, file) == 0)
		return ;
	if (x->flag.t > 0)
		get_file_t(file, x);
	else if (x->flag.l >= 1)
	{
		if (S_ISDIR(filestat.st_mode) && x->flag.rr == 0)
			dir_arg(x, file);
		else
			get_file2(file, x);
	}
	else
	{
		else_helper(filestat, x, file);
	}
}

/*
** START_FLAG
** ---------------------------------------------------------------------------
** Esta fucion inicializa la estructura FLAG para saber que operaciones vamos
** a realizar, si o que archivos o directorios vamos a identificar.
*/

void		start_flag(char **argv, t_top *x)
{
	x->flag.i = 1;
	x->flag.j = 0;
	{
		while (argv[x->flag.i])
		{
			if (argv[x->flag.i][0] == '-')
			{
				while (argv[x->flag.i][++x->flag.j])
				{
					x->flag.l += (argv[x->flag.i][x->flag.j] == 'l') ? 1 : 0;
					x->flag.rr += (argv[x->flag.i][x->flag.j] == 'R') ? 1 : 0;
					x->flag.a += (argv[x->flag.i][x->flag.j] == 'a') ? 1 : 0;
					x->flag.r += (argv[x->flag.i][x->flag.j] == 'r') ? 1 : 0;
					x->flag.t += (argv[x->flag.i][x->flag.j] == 't') ? 1 : 0;
					x->flag.aa += (argv[x->flag.i][x->flag.j] == 'A') ? 1 : 0;
					x->flag.f += (argv[x->flag.i][x->flag.j] == 'f') ? 1 : 0;
				}
			}
			else
				get_file(argv[x->flag.i], x);
			x->flag.i++;
			x->flag.j = 0;
		}
	}
}

/*
** FLAG_ZERO
** ---------------------------------------------------------------------------
** Funcion para inicializar valores en 0 y evitar problemas.
*/

void		flag_zero(t_top *x)
{
	x->flag.l = 0;
	x->flag.rr = 0;
	x->flag.r = 0;
	x->flag.a = 0;
	x->flag.aa = 0;
	x->flag.t = 0;
	x->flag.rec = 0;
	x->flag.f = 0;
	x->type.l = 0;
	x->flag.error = 0;
	x->dir.i = 0;
}
