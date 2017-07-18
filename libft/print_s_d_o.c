/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:37:43 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 21:37:44 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						print_o(va_list ap, int flag)
{
	char				*s;
	unsigned long int	n;

	n = va_arg(ap, unsigned long int);
	if (n == 0 && flag == 1)
		return (1);
	s = ft_l_itoa_base(n, 8);
	ft_putstr(s);
	return (ft_strlen(s));
}

int						print_s(char *s)
{
	int					i;

	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	i = ft_strlen(s);
	return (i);
}

int						print_c(va_list ap)
{
	char				c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int						ll_d(long long n)
{
	return (ft_lputnbr(n));
}

int						print_d(va_list ap, int flag, int space)
{
	t_head				*i;

	i = (t_head*)malloc(sizeof(t_head));
	i->head_d.value = va_arg(ap, int);
	if (space == 1 && i->head_d.value > 0)
		write(1, " ", 1);
	if (i->head_d.value >= 0 && flag == 1)
	{
		write(1, "+", 1);
		ft_putnbr(i->head_d.value);
		return (number_len(i) + 1);
	}
	ft_putnbr(i->head_d.value);
	return (number_len(i) + space);
}
