/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:41:14 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/11 15:41:15 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./libft/libft.h"
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>

# define KEY_DAR		10
# define KEY_ESC		27
# define KEY_SPC		32
# define KEY_STAR		42
# define KEY_MINUS		45
# define KEY_BSP		127
# define KEY_IZQ		4479771
# define KEY_ARR		4283163
# define KEY_DER		4414235
# define KEY_ABJ		4348699
# define KEY_DEL		2117294875L


typedef	struct			s_var
{
	struct termios		term;
	int					x;
	int					y;
	int					len;
	int					full;
	int					largo;
	int					width;
	int					height;
	int					cursor;
	int					num_obj;
	int					arg_width;
	int					arg_height;
	int					total_selected;
	int					*select;
	char				buffer[2048];
	char				**objects;
}						t_var;

int						max_width(char **mtx);
t_var					*saved_env(t_var *env);
t_var					*safe_t_var(t_var *x, int flag);
void					logo(t_var *x);
void					read_key(t_var *x);
void					size_term(t_var *x);
void					mode_str(char *str);
void					ft_clrscreen(int rows);
void					return_values(t_var *x);
void					print_screen_se(int sig);
void					ft_cursor_goto(int x, int y);
void					key_space(t_var *x, long key);
void					print_objects(t_var *x, int i);
void					len_obj(char **matrix, int i, t_var *x);

#endif

/*
**
** ---------------------------------------------------------------------------
**
*/
