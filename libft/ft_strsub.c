/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:02:16 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/12 20:02:18 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*x;
	size_t	i;

	if (!s)
		return (NULL);
	x = ft_strnew(len);
	if (x == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (i < len)
	{
		x[i] = s[i];
		i++;
	}
	return (x);
}
