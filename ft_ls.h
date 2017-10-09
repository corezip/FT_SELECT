/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "./libft/libft.h"
# include <errno.h>
# include <string.h>
# include <sys/xattr.h>

/*
** ---------------------------------------------------------------------------
** *nums ---> contiene el valor convertido de los permisos ej. drwxr-xr-x.
** i y j ---> son simples contadores para los whiles o char*.
** size ---> es el tamaño en bytes de los archivos.
** flag --> sirve para identificar si obtuvimos un file.
** mtime ---> Es la variable donde vamos a recibir el tiempo.
** new_time ---> Es la variable del tiempo ya recortado listo para imprimir.
** perm ---> es la variable para poder hacer la conversion de los permisos.
*/

typedef	struct			s_perm
{
	int					i;
	int					j;
	int					size;
	int					num;
	int					flag;
	int					l;
	char				*tmp;
	char				*tmp2;
	char				*tmp3;
}						t_perm;

typedef	struct			s_dir
{
	struct dirent		*pdirent;
	struct stat			filestat;
	DIR					*pdir;
	struct stat			buff;
	int					i;
	char				**matrix;
	char				*tmp;
}						t_dir;

/*
** ---------------------------------------------------------------------------
** Las flags sirven para saber si recibo "-".
*/

typedef	struct			s_flag
{
	int					l;
	int					rr;
	int					a;
	int					aa;
	int					r;
	int					t;
	int					file;
	int					rec;
	int					i;
	int					j;
	int					f;
	int					error;
}						t_flag;

/*
** ---------------------------------------------------------------------------
** Estructura general.
*/

typedef	struct			s_top
{
	t_perm				type;
	t_flag				flag;
	t_dir				dir;
}						t_top;

void					print_basic(t_top *x, char *path);
void					ls_menu(t_top *x, char *path);
void					start_flag(char **argv, t_top *x);
int						flag_on(t_top *x);
void					ft_swapchar(char **a, char **b);
void					ft_print_matrix(char **matrix);
char					**ft_make_matrix(int size, t_top *x, char *path);
int						ft_lendir(t_top *x, char *path);
int						print_value_ls(char *file);
void					print_blocks_size(t_top *x, char *path);
void					comp_matrix(t_top *x, char **matrix, char *path);
int						print_value_recu(char *file, char *path);
void					recurtion_mexa(char *path, t_top *x, int i);
void					comp_matrix_r(t_top *x, char **matrix);
void					especial_comp_matrix(t_top *x, char **matrix,
	char *path);
void					print_especial(char *path, char **matrix, int i);
void					recursion_comp_rev(t_top *x, char **matrix);
void					comp_rev(t_top *x, char **matrix, char *path);
void					comp_normal(t_top *x, char **matrix, char *path);
void					flag_zero(t_top *x);
void					print_l(t_top *x, char *path, char **matrix);
void					ft_ls_t(t_top *x, char *path);
void					comp_matrix_t(t_top *x, char **matrix,
	char **times, char *path);
void					comp_matrix_t_r(t_top *x, char **matrix,
	char **times, char *path);
char					**ft_catching_time(int size, t_top *x, char
	**files, char *path);
void					print_basic_t(t_top *x, char **matrix, char **times);
void					print_basic_t_r(t_top *x, char **matrix,
	char **times);
void					option_t(t_top *x, char *file, char *path);
void					recurtion_mexa_t(char *path, t_top *x, int i);
void					get_file_t(char *file, t_top *x);
void					get_file2(char *file, t_top *x);
char					**ft_catching_time_r(int size, t_top *x,
	char **files, char *path);
int						security_path(char *path);
int						print_stat(struct stat filestat);
void					only_dot(t_top *x, char *path);
char					**matrix_sort(t_top *x, char **matrix);
char					**matrix_sort_reverse(t_top *x, char **matrix);
void					dir_arg(t_top *x, char *path);
char					*get_link(char *path);
void					no_sort(t_top *x, char *path);
void					else_helper(struct stat filestat, t_top *x, char *file);
int						get_file_error(struct stat filestat, char *file);
void					print_name(struct stat filestat, char *file, int i);
int						safe_lines(DIR **pdir, char *path, t_top *x);
char					**safe_recurtion(t_top *x, char *path);
void					print_basic_color(char *file);

#endif
