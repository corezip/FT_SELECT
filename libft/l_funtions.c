/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_funtions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:37:43 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 21:37:44 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_lputnbr(long long n)
{
	int						x;

	x = 0;
	if (n == -9223372036854775807)
		ft_putstr("-9223372036854775807");
	if (n < 0 && n > -9223372036854775807)
	{
		ft_putchar('-');
		n *= -1;
		x += 1;
	}
	if (n < 10 && n > -9223372036854775807)
		ft_putchar(n + 48);
	else if (n >= 10)
	{
		x += 1;
		ft_lputnbr(n / 10);
		ft_lputnbr(n % 10);
	}
	return (n);
}

int							ft_digitnuml(unsigned long long int n, int base)
{
	int						i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char						*ft_l_itoa_base(unsigned long long int value,
	int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789ABCDEF");
	if (value == 0 || base < 2 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	tmp = value;
	len = ft_digitnuml(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}

char						*wide_to_string(wint_t w)
{
	char					*p;

	p = ft_strnew(4);
	if (w <= 0x0ff)
		p[0] = w;
	else if (w <= 0x07ff)
	{
		p[0] = (w >> 6) + 0xc0;
		p[1] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0xFFFF)
	{
		p[0] = (w >> 12) + 0xe0;
		p[1] = ((w >> 6) & 0x3f) + 0x80;
		p[2] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0x10FFFF)
	{
		p[0] = (w >> 18) + 0xf0;
		p[1] = (w >> 12 & 0x3f) + 0x80;
		p[2] = (w >> 6 & 0x3f) + 0x80;
		p[3] = (w & 0x3f) + 0xc80;
	}
	return (p);
}

int							print_l_c(wint_t w)
{
	char					*s;

	s = wide_to_string(w);
	if (w == 0)
		return (0);
	else
		ft_putstr(s);
	return (ft_strlen(s));
}
