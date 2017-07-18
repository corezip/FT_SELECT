/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:52:51 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/22 16:52:53 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			value_space(t_head *z, int x)
{
	if (z->head_zero.num > z->head_d.flag)
	{
		z->head_zero.ilen = z->head_zero.num - z->head_d.flag - x;
		while (++z->head_d.count != z->head_zero.ilen)
			write(1, "0", 1);
		z->head_zero.num = z->head_zero.ilen +
		(ft_strlen(ft_itoa(z->head_d.value)));
		return (z->head_zero.ilen + (ft_strlen(ft_itoa(z->head_d.value))));
	}
	return (0);
}

/*
** x->head_pr.presition =z->head_zero.num;
*/

int			dot_zer(char *****fmt, va_list ap, t_head *x, int flag)
{
	****fmt += 1;
	x->head_pr.space = x->head_zero.num;
	x->head_pr.i = 0;
	ft_bzero(x->head_pr.str, 99);
	while (*****fmt >= '0' && *****fmt <= '9')
	{
		x->head_pr.str[x->head_pr.i++] = *****fmt + 0;
		****fmt += 1;
	}
	x->head_pr.presition = ft_atoi(x->head_pr.str);
	if (*****fmt == 'd' || *****fmt == 'i')
	{
		if (x->head_pr.space <= x->head_pr.presition)
			return (equal_less_d(va_arg(ap, int), x, flag, 0));
		else if (x->head_pr.space > x->head_pr.presition)
			return (plus_d(va_arg(ap, int), x, flag, 0));
	}
	return (0);
}

int			choose_zero(char ****fmt, va_list ap, t_head *z, int flag)
{
	z->head_d.count = -1;
	if (****fmt == 'd' || ****fmt == 'i')
	{
		z->head_d.value = va_arg(ap, int);
		if (z->head_d.value > 0 && flag == 1)
			write(1, "+", 1);
		z->head_d.flag = ft_strlen(ft_itoa(z->head_d.value));
		if (z->head_d.value < 0)
		{
			write(1, "-", 1);
			z->head_d.value = z->head_d.value * (-1);
			flag += 1;
		}
		if (value_space(z, flag) > 0)
		{
			ft_printf("%d", z->head_d.value);
			return ((z->head_zero.ilen + z->head_d.flag) + flag);
		}
		ft_putnbr(z->head_d.value);
		return (number_len(z) + flag);
	}
	if (****fmt == '.')
		return (dot_zer(&fmt, ap, z, flag));
	return (0);
}

int			zero_w(char ****fmt, va_list ap, int flag)
{
	t_head	*z;

	***fmt += 1;
	z = (t_head*)malloc(sizeof(t_head));
	z->head_zero.ilen = 0;
	if (****fmt == '+')
	{
		flag = 1;
		***fmt += 1;
	}
	while (****fmt >= '0' && ****fmt <= '9')
	{
		z->head_zero.convert[z->head_zero.ilen] = ****fmt + 0;
		***fmt += 1;
		z->head_zero.ilen++;
	}
	z->head_zero.num = ft_atoi(z->head_zero.convert);
	return (choose_zero(fmt, ap, z, flag));
}
