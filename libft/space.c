/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:37:31 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 14:37:33 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				pre_s(t_head *x, va_list ap, int flag)
{
	x->head_s.value = va_arg(ap, char*);
	x->head_s.len = ft_strlen(x->head_s.value);
	if (flag == 1)
		return (print_s_positive(x));
	else
		return (print_s_negative(x));
}

int				print_d_negative(t_head *x)
{
	if (x->head_d.len > x->head_pr.space)
	{
		ft_putstr(x->head_d.str);
		return (x->head_d.len);
	}
	else
	{
		x->head_d.count = 0;
		ft_putstr(x->head_d.str);
		x->head_d.len = x->head_pr.space - x->head_d.len;
		while (x->head_d.len != x->head_d.count)
		{
			write(1, " ", 1);
			x->head_d.count += 1;
		}
		return (x->head_pr.space);
	}
	return (0);
}

int				print_d_positive(t_head *x)
{
	if (x->head_d.len > x->head_pr.space)
	{
		ft_putstr(x->head_d.str);
		return (x->head_d.len);
	}
	else
	{
		x->head_d.count = 0;
		x->head_d.len = x->head_pr.space - x->head_d.len;
		while (x->head_d.len != x->head_d.count)
		{
			write(1, " ", 1);
			x->head_d.count += 1;
		}
		ft_putstr(x->head_d.str);
		return (x->head_pr.space);
	}
}

/*
**x->head_pr.space tiene el valor de los espacios que piden poner.
*/

int				pre_d_s(t_head *x, va_list ap, int flag)
{
	x->head_d.value = va_arg(ap, int);
	x->head_d.str = ft_itoa(x->head_d.value);
	x->head_d.len = ft_strlen(x->head_d.str);
	if (flag == 0)
		return (print_d_positive(x));
	else
		return (print_d_negative(x));
}

int				space_d(char ****fmt, va_list ap, int flag, int i)
{
	t_head		*x;

	x = (t_head*)malloc(sizeof(t_head));
	x->head_pr.i = 0;
	x->head_pr.negative = i;
	while (****fmt >= '0' && ****fmt <= '9')
	{
		x->head_pr.str[x->head_pr.i++] = ****fmt + 0;
		***fmt += 1;
	}
	x->head_pr.space = ft_atoi(x->head_pr.str);
	if (****fmt == '.')
		return (values_presition(&fmt, ap, x, flag));
	if (****fmt == 'd' || ****fmt == 'i')
		return (pre_d_s(x, ap, i));
	else if (****fmt == 's' || ****fmt == 'S')
	{
		if (i == 1)
			return (values_presition(&fmt, ap, x, flag));
		else
			return (pre_s(x, ap, flag));
	}
	return (0);
}
