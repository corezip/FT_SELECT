/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:50:29 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/14 16:50:31 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wclen(wchar_t wc)
{
	int			len;

	len = 0;
	if (wc <= 0xFF)
		len = 1;
	else if (wc < 0x0800)
		len = 2;
	else if (wc < 0x010000)
		len = 3;
	else if (wc < 0x110000)
		len = 4;
	return (len);
}

int				ft_putwstr(wchar_t *wcs)
{
	int			len;

	len = 0;
	while (*wcs)
	{
		ft_putwchar(*wcs);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
