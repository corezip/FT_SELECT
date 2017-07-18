/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xnumber.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:18:39 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/21 20:18:40 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				resul_hex(t_head *x)
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

int				print_x_upper(va_list ap)
{
	t_head		*x;

	x = (t_head*)malloc(sizeof(t_head));
	x->head_x.hexadecimalnumber = (char*)ft_memalloc(100);
	x->head_x.decimalnumber = va_arg(ap, long);
	if (x->head_x.decimalnumber >= 0)
		resul_hex(x);
	else
	{
		x->head_x.decimalnumber = x->head_x.decimalnumber + 4294967296;
		resul_hex(x);
	}
	reverse_array(x->head_x.hexadecimalnumber);
	ft_putstr(x->head_x.hexadecimalnumber);
	return (x->head_x.count);
}

int				print_x(va_list ap)
{
	t_head		*x;

	x = (t_head*)malloc(sizeof(t_head));
	x->head_x.hexadecimalnumber = (char*)ft_memalloc(100);
	x->head_x.decimalnumber = va_arg(ap, long);
	if (x->head_x.decimalnumber >= 0)
		resul_hex(x);
	else
	{
		x->head_x.decimalnumber = x->head_x.decimalnumber + 4294967296;
		resul_hex(x);
	}
	reverse_array(x->head_x.hexadecimalnumber);
	ft_strlowcase(x->head_x.hexadecimalnumber);
	ft_putstr(x->head_x.hexadecimalnumber);
	return (x->head_x.count);
}
