/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:37:31 by gsolis            #+#    #+#             */
/*   Updated: 2017/03/10 14:37:33 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ll_uns(unsigned long long int x, int flag, int z)
{
	char		*str;
	int			i;

	str = ft_l_itoa_base(x, flag);
	if (z == 1)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = (str[i] - 32);
			}
			i++;
		}
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int				print_ls(va_list ap)
{
	wchar_t		*s;

	s = va_arg(ap, wchar_t*);
	return (ft_putwstr(s));
}

int				hh_funtion(char *****fmt, va_list ap)
{
	****fmt += 1;
	if (*****fmt == 'i' || *****fmt == 'd' || *****fmt == 'u' ||
		*****fmt == 'D')
		return (ll_uns(va_arg(ap, unsigned long long int), 10, 0));
	else if (*****fmt == 'x')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 0));
	else if (*****fmt == 'X')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 1));
	else if (*****fmt == 'o')
		return (ll_uns(va_arg(ap, unsigned long long int), 8, 0));
	else if (*****fmt == 'c' || *****fmt == 'C')
		return (print_l_c(va_arg(ap, wint_t)));
	return (0);
}

int				ll_funtion(char *****fmt, va_list ap)
{
	****fmt += 1;
	if (*****fmt == 'i' || *****fmt == 'd' || *****fmt == 'u')
		return (ll_uns(va_arg(ap, unsigned long long int), 10, 0));
	else if (*****fmt == 'x')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 0));
	else if (*****fmt == 'X')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 1));
	else if (*****fmt == 'o')
		return (ll_uns(va_arg(ap, unsigned long long int), 8, 0));
	return (0);
}

int				l_funtion(char ****fmt, va_list ap)
{
	***fmt += 1;
	if (****fmt == 'i' || ****fmt == 'd' || ****fmt == 'u' || ****fmt == 'D')
		return (ll_uns(va_arg(ap, unsigned long long int), 10, 0));
	else if (****fmt == 'x')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 0));
	else if (****fmt == 'X')
		return (ll_uns(va_arg(ap, unsigned long long int), 6, 1));
	else if (****fmt == 'o')
		return (ll_uns(va_arg(ap, unsigned long long int), 8, 0));
	else if (****fmt == 'c' || ****fmt == 'C')
		return (print_l_c(va_arg(ap, wint_t)));
	else if (****fmt == 's' || ****fmt == 'S')
		return (print_ls(ap));
	else if (****fmt == 'l')
		return (ll_funtion(&fmt, ap));
	else if (****fmt == 'h')
		return (hh_funtion(&fmt, ap));
	return (0);
}
