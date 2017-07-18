/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/17 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_digitnum(int n, int base)
{
	int			i;

	i = 0;
	while ((n = n / base))
		i++;
	return (i + 1);
}

char			*ft_itoa_base(int n, int b)
{
	char		*num;
	size_t		size;
	int			neg;
	int			mod;

	neg = 0;
	size = ft_digitnum(n, b);
	if (n < 0 && b == 10)
		neg++;
	num = ft_strnew(size);
	if (neg)
		num[0] = '-';
	num[size + neg] = 0;
	while (size--)
	{
		mod = ((n % b) < 0 ? -(n % b) : (n % b));
		num[size + neg] = ((mod > 9) ? mod + 55 : mod + '0');
		n /= b;
	}
	return (num);
}

char			*reverse_array(char *s)
{
	int			i;
	int			j;
	char		*x;

	j = 0;
	i = ft_strlen(s);
	x = (char*)malloc(i + 1);
	i -= 1;
	while (i != -1)
	{
		x[j] = s[i];
		i--;
		j++;
	}
	x[j] = '\0';
	ft_strcpy(s, x);
	free(x);
	return (s);
}

char			*ft_strlowcase(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] + 32);
		}
		i++;
	}
	return (str);
}

void			u_putnbr(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
