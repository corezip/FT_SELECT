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
** PRINT_BASIC_T
** ---------------------------------------------------------------------------
** Esta funcion hara el acomodado de la flag "t" y hara la impresion del
** nombre sin mas atributos.
*/

void				print_basic_t(t_top *x, char **matrix, char **times)
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
		print_basic_color(matrix[x->type.j]);
}

/*
** PRINT_BLOCKS_SIZE
** ---------------------------------------------------------------------------
** Esta funcion obtendra el tamaño de los bloques que utiliza cada archivo.
** Toma en cuenta la opcion de contar con archivos ocultos o sin ellos.
*/

void				print_blocks_size(t_top *x, char *path)
{
	struct dirent	*pdirent;

	if (!(x->dir.pdir = opendir(path)))
	{
		ft_printf("Error: %s\n", strerror(errno));
		return ;
	}
	x->dir.i = 0;
	while ((pdirent = readdir(x->dir.pdir)) != NULL)
	{
		stat(pdirent->d_name, &x->dir.buff);
		if (pdirent->d_name[0] == '.' && x->flag.a >= 1)
		{
			x->type.size += x->dir.buff.st_blocks;
			x->dir.i++;
		}
		else if (pdirent->d_name[0] != '.' && (x->flag.a == 0 ||
			x->flag.a > 0))
		{
			x->type.size += x->dir.buff.st_blocks;
			x->dir.i++;
		}
	}
	ft_printf("Total: %d\n", x->type.size);
	closedir(x->dir.pdir);
}

/*
** PRINT_VALUE_RECU
** ---------------------------------------------------------------------------
** Esta funcion hara la impresion de los archivos con la flag -R -l activa,
** hara la union del file junto con el path, dando como resultado la dirrecion
** correcta, para poder buscar el archivo dentro de esa direccion e imprimir
** toda su informacion.
*/

int					print_value_recu(char *file, char *path)
{
	struct stat		filestat;
	struct passwd	*pw;
	struct group	*gr;
	char			*tmp;
	int				i;

	path = ft_strjoin(path, "/");
	tmp = ft_strjoin(path, file);
	lstat(tmp, &filestat);
	pw = getpwuid(filestat.st_uid);
	gr = getgrgid(filestat.st_gid);
	i = print_stat(filestat);
	ft_printf(listxattr(tmp, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
	ft_printf("  %d %s  %s %7d ", filestat.st_nlink, pw->pw_name,
		gr->gr_name, filestat.st_size);
	if (i == 0 && !(S_ISDIR(filestat.st_mode)))
		ft_printf("%s %s\n", ft_strsub(ctime(&filestat.st_ctime), 4, 12), file);
	else if (i == 1)
		ft_printfcolor("%s %s -> %s\n", ft_strsub(ctime(&filestat.st_ctime),
			4, 12), 39, file, 34, get_link(tmp), 31);
	else
		ft_printfcolor("%s %s\n", ft_strsub(ctime(&filestat.st_ctime), 4, 12),
			39, file, 34);
	return (filestat.st_blocks);
}

/*
** PRINT_VALUE_LS
** ---------------------------------------------------------------------------
** Esta funcion es la impresion para las flag -l o que contenga -l sin haber
** recibido un file o carpeta por argumento. en caso de recibir como
** argumento un file o directorio se usara PRINT_VALUE_RECU
*/

int					print_value_ls(char *file)
{
	struct stat		filestat;
	struct passwd	*pw;
	struct group	*gr;
	int				i;

	if (lstat(file, &filestat) < 0)
		return (1);
	pw = getpwuid(filestat.st_uid);
	gr = getgrgid(filestat.st_gid);
	i = print_stat(filestat);
	ft_printf(listxattr(file, 0, 0, XATTR_NOFOLLOW) > 0 ? "@" : " ");
	ft_printf("  %d %s  %s %7d ", filestat.st_nlink, pw->pw_name,
		gr->gr_name, filestat.st_size);
	if (i == 0 && !(S_ISDIR(filestat.st_mode)))
		ft_printf("%s %s\n", ft_strsub(ctime(&filestat.st_ctime), 4, 12), file);
	else if (i == 1)
		ft_printfcolor("%s %s -> %s\n", ft_strsub(ctime(&filestat.st_ctime),
			4, 12), 39, file, 34, get_link(file), 31);
	else
		ft_printfcolor("%s %s\n", ft_strsub(ctime(&filestat.st_ctime), 4, 12),
			39, file, 34);
	return (filestat.st_blocks);
}

/*
** PRINT_BASIC
** ---------------------------------------------------------------------------
** esta funcion imprimira en orden ASCII(A - Z) solo los nombres de los
** archivos sin inforacion.
*/

void				print_basic(t_top *x, char *path)
{
	char			**matrix;

	x->type.flag = 1;
	x->type.j = 0;
	x->type.i = ft_lendir(x, path);
	matrix = ft_make_matrix(x->type.i, x, path);
	matrix = matrix_sort(x, matrix);
	x->type.j = -1;
	while (matrix[++x->type.j] != NULL)
		print_basic_color(matrix[x->type.j]);
}
