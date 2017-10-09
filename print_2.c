/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** PRINT_STAT
** ---------------------------------------------------------------------------
** Esta funcion imprimira los stats de los archivos que contenga la estructura.
*/

int					print_stat(struct stat filestat)
{
	int				i;

	i = 0;
	if (S_ISLNK(filestat.st_mode))
	{
		ft_printf("l");
		i = 1;
	}
	else
		ft_printf((S_ISDIR(filestat.st_mode)) ? "d" : "-");
	ft_printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
	return (i);
}

char				*get_link(char *path)
{
	char			*buf;
	ssize_t			len;

	buf = (char*)malloc(sizeof(char*) * 1024);
	len = readlink(path, buf, 1023);
	if (len < 1)
	{
		ft_printf("Error: %s\n", strerror(errno));
		return (NULL);
	}
	buf[len] = '\0';
	return (buf);
}

void				dir_arg(t_top *x, char *path)
{
	char **matrix;

	x->flag.rr = 1;
	print_blocks_size(x, path);
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	if (x->flag.l >= 1 || (x->flag.file >= 1 && x->flag.l >= 1))
		comp_matrix(x, matrix, path);
	else
		comp_matrix_r(x, matrix);
}

void				print_name(struct stat filestat, char *file, int i)
{
	lstat(file, &filestat);
	if (S_ISDIR(filestat.st_mode) && i == 0)
		ft_printfcolor("%s\n", file, 94);
	if (S_ISDIR(filestat.st_mode) && i == 1)
		ft_printfcolor("%s -> %s\n", file, 94, get_link(file), 39);
	else
		ft_printf("%s\n", file);
}
