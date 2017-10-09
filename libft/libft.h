/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:12:15 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/05 11:12:20 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 8

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <locale.h>
# include <wchar.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_pres
{
	int				space;
	int				presition;
	int				i;
	int				calc;
	int				negative;
	char			str[100];
}					t_pres;

typedef	struct		s_main
{
	int				count;
	int				len;
	char			*format;
}					t_main;

typedef	struct		s_u
{
	unsigned int	value;
	int				count;
	int				flag;
	long int		i;
}					t_u;

typedef	struct		s_ld
{
	long long		value;
	long long		count;
}					t_ld;

typedef	struct		s_d
{
	int				value;
	int				count;
	int				flag;
	int				len;
	char			*str;
}					t_d;

typedef	struct		s_s
{
	char			*value;
	int				len;
	int				count;
}					t_s;

typedef	struct		s_o
{
	int				remainder;
	int				octal;
	int				i;
	int				n;
	int				x;
}					t_o;

typedef	struct		s_x
{
	long int		decimalnumber;
	long int		remainder;
	long int		quotient;
	long int		i;
	int				count;
	int				value;
	int				temp;
	char			*hexadecimalnumber;
	char			*hexa;
}					t_x;

typedef	struct		s_zero
{
	int				ilen;
	char			convert[20];
	char			*tmp;
	int				num;
}					t_zero;

typedef	struct		s_head
{
	t_d				head_d;
	t_s				head_s;
	t_o				head_o;
	t_x				head_x;
	t_u				head_u;
	t_zero			head_zero;
	t_pres			head_pr;
	t_ld			head_ll;
}					t_head;

void				ft_putchar(int c);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strchr(const char *s, int c);
void				ft_putchar_fd(char c, int fd);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_memdel(void **ap);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
	size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strclr(char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_atoi(const char *str);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(const char *s, char c);
char				*ft_strtrim(const char *s);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa(int n);
void				ft_lstaddend(t_list **alst, t_list *new);
int					ft_wordcount(char const *s, char c);
char				*ft_nextword(const char *s, char c, size_t *ele);
void				ft_swap(int *a, int *b);
int					ft_putwstr(wchar_t *wcs);
int					ft_putwchar(wchar_t wc);
int					ft_printf(const char *fmt, ...);
int					print_s(char *s);
int					print_c(va_list ap);
int					print_d(va_list ap, int flag, int space);
int					print_o(va_list ap, int flag);
int					print_x(va_list ap);
int					print_x_upper(va_list ap);
int					print_p(va_list ap);
int					print_u(va_list ap);
int					print_m();
int					read_con(char **fmt, va_list ap, int space);
int					extra_con(char ***fmt, va_list ap, int flag);
void				un_putnbr(unsigned int n);
char				*reverse_array(char *s);
char				*ft_strlowcase(char *str);
int					u_calc(long int n);
void				u_putnbr(unsigned int n);
int					resul_hex(t_head *x);
int					hash(char ***fmt, va_list ap);
int					zero_w(char ****fmt, va_list ap, int flag);
int					dot_zer(char *****fmt, va_list ap, t_head *z, int flag);
int					number_len(t_head *i);
int					mult_options(char ***fmt, va_list ap);
int					space_d(char ****fmt, va_list ap, int flag, int i);
int					print_d_positive(t_head *x);
int					pre_d_s(t_head *x, va_list ap, int flag);
int					print_d_negative(t_head *x);
int					pre_s(t_head *x, va_list ap, int flag);
int					values_presition(char *****fmt, va_list ap,
	t_head *x, int flag);
int					equal_less_d(int value, t_head *x, int flag, int count);
int					plus_d(int value, t_head *x, int flag, int count);
int					extra_d(int value, t_head *x, int flag, int count);
int					s_values(char *s, t_head *x, int flag, int negative);
int					second_option(char *s, t_head *x);
char				*ft_itoa_base(int value, int base);
int					ft_digitnum(int n, int base);
int					l_funtion(char ****fmt, va_list ap);
int					ll_funtion(char *****fmt, va_list ap);
int					ll_d(long long n);
int					ft_lputnbr(long long n);
int					print_l_c(wint_t w);
char				*ft_l_itoa_base(unsigned long long int value, int base);
int					ll_uns(unsigned long long int x, int flag, int z);
int					print_s_negative(t_head *x);
int					print_s_positive(t_head *x);
int					get_next_line(int const fd, char **line);
void				ft_printfcolor(const char *format, ...);
void				putcstr(char const *s, size_t col);
void				set_color(int c);

#endif
