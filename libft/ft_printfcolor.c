/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 01:15:50 by gsolis            #+#    #+#             */
/*   Updated: 2017/05/11 01:15:51 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		set_color(int c)
{
	ft_putstr("\033[");
	ft_putnbr(c);
	ft_putchar('m');
}

void		putcstr(char const *s, size_t col)
{
	if (s)
	{
		set_color(col);
		ft_putstr(s);
		set_color(0);
	}
}

void		ft_printfcolor(const char *format, ...)
{
	va_list p;

	va_start(p, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if ((*(format + 1)) == 's')
				putcstr(va_arg(p, char*), va_arg(p, size_t));
			else if ((*(format + 1)) == 'd')
				putcstr(ft_itoa(va_arg(p, int)), va_arg(p, size_t));
			format += 1;
		}
		else
			write(1, format, 1);
		format += 1;
	}
	va_end(p);
}
