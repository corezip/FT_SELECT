/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 19:29:47 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/17 19:29:49 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				resul_p(t_head *x)
{
	x->head_x.count = 0;
	if (x->head_x.decimalnumber == 0)
	{
		write(1, "0", 1);
		x->head_x.count += 1;
	}
	x->head_x.i = 0;
	x->head_x.quotient = x->head_x.decimalnumber;
	while (x->head_x.quotient != 0)
	{
		x->head_x.temp = x->head_x.quotient % 16;
		if (x->head_x.temp < 10)
			x->head_x.temp = x->head_x.temp + 48;
		else
			x->head_x.temp = x->head_x.temp + 55;
		x->head_x.hexadecimalnumber[x->head_x.i++] = x->head_x.temp;
		x->head_x.quotient = x->head_x.quotient / 16;
		x->head_x.count++;
	}
	return (x->head_x.count);
}

int				p_solver(long i)
{
	t_head		*x;

	x = (t_head*)malloc(sizeof(t_head));
	x->head_x.hexadecimalnumber = (char*)ft_memalloc(100);
	x->head_x.decimalnumber = i;
	if (x->head_x.decimalnumber >= 0)
		resul_p(x);
	else
	{
		x->head_x.decimalnumber = x->head_x.decimalnumber + 4294967296;
		resul_p(x);
	}
	reverse_array(x->head_x.hexadecimalnumber);
	ft_strlowcase(x->head_x.hexadecimalnumber);
	ft_putstr(x->head_x.hexadecimalnumber);
	return (x->head_x.count);
}

int				print_p(va_list ap)
{
	long			i;

	write(1, "0x", 2);
	i = (long)va_arg(ap, void*);
	i = p_solver(i);
	return (i);
}

int				print_m(void)
{
	write(1, "%", 1);
	return (1);
}

int				print_u(va_list ap)
{
	t_head		*i;

	i = (t_head*)malloc(sizeof(t_head));
	i->head_u.value = (unsigned int)va_arg(ap, int);
	u_putnbr(i->head_u.value);
	i->head_u.count = 1;
	i->head_u.flag = 0;
	while (i->head_u.flag == 1 || (i->head_u.value / 10 > 0 && i->head_u.flag
		== 0))
	{
		i->head_u.value = i->head_u.value / 10;
		i->head_u.count++;
	}
	return (i->head_u.count);
}
