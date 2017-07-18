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

int				print_s_negative(t_head *x)
{
	if (x->head_s.len > x->head_pr.space)
	{
		ft_putstr(x->head_s.value);
		return (x->head_s.len);
	}
	else
	{
		x->head_s.count = 0;
		x->head_s.len = x->head_pr.space - x->head_s.len;
		ft_putstr(x->head_s.value);
		while (x->head_s.len != x->head_s.count)
		{
			write(1, " ", 1);
			x->head_s.count += 1;
		}
		return (x->head_pr.space);
	}
}

int				print_s_positive(t_head *x)
{
	if (x->head_s.len > x->head_pr.space)
	{
		ft_putstr(x->head_s.value);
		return (x->head_s.len);
	}
	else
	{
		x->head_s.count = 0;
		x->head_s.len = x->head_pr.space - x->head_s.len;
		while (x->head_s.len != x->head_s.count)
		{
			write(1, " ", 1);
			x->head_s.count += 1;
		}
		ft_putstr(x->head_s.value);
		return (x->head_pr.space);
	}
}

int				number_len(t_head *i)
{
	i->head_d.count = 1;
	i->head_d.flag = 0;
	if (i->head_d.value < 0)
	{
		i->head_d.flag = 1;
		i->head_d.count++;
	}
	while ((i->head_d.value / 10 < 0 && (i->head_d.flag == 1)) ||
	(i->head_d.value / 10 > 0 && i->head_d.flag == 0))
	{
		i->head_d.value = i->head_d.value / 10;
		i->head_d.count++;
	}
	return (i->head_d.count);
}
