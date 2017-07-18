/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pretition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:37:31 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 14:37:33 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				second_option(char *s, t_head *x)
{
	x->head_s.count = 0;
	while (x->head_s.count != (x->head_pr.space - x->head_s.len))
	{
		write(1, " ", 1);
		x->head_s.count += 1;
	}
	return (print_s(s) + x->head_s.count);
}

int				third_option(char *s, t_head *x)
{
	x->head_s.count = 0;
	x->head_x.i = print_s(s);
	while (x->head_s.count != (x->head_pr.space - x->head_s.len))
	{
		write(1, " ", 1);
		x->head_s.count += 1;
	}
	return (x->head_x.i + x->head_s.count);
}

int				four_option(char *s, t_head *x)
{
	x->head_s.count = 0;
	x->head_x.i = 0;
	while (x->head_s.count < x->head_pr.presition)
	{
		write(1, &s[x->head_s.count], 1);
		x->head_s.count += 1;
		x->head_x.i += 1;
	}
	x->head_s.count = 0;
	while (x->head_s.count <= (x->head_pr.space - x->head_s.len))
	{
		write(1, " ", 1);
		x->head_s.count += 1;
		x->head_x.i += 1;
	}
	return (x->head_x.i);
}

/*
** presition sera el primer numero %-->4<--.3s
** space sera el segundo numero %4.-->3<--s
** si el primer numero es mas chico que el segundo solo se debe realizar el
** segundo, o sea, solo se imprimira 3 caracteres si es que es lo suficiente
** grande el string.
*/

int				s_values(char *s, t_head *x, int flag, int negative)
{
	if (x->head_pr.space <= x->head_pr.presition && x->head_pr.space <=
		x->head_s.len)
		return (print_s(s) + negative + flag);
	else if ((x->head_pr.space > x->head_pr.presition && negative == 0) &&
		(x->head_pr.space > x->head_s.len && (negative == 0)))
		return (second_option(s, x));
	else if ((negative == 1) && (x->head_pr.space <= x->head_pr.presition &&
		x->head_pr.space >= x->head_s.len))
		return (third_option(s, x));
	else if (negative == 1 && (x->head_pr.presition < x->head_pr.space))
		return (four_option(s, x));
	return (negative + flag);
}
