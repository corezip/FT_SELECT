/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:53:41 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/09 13:53:43 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*i;
	char	*x;

	if (!*little)
		return ((void *)big);
	while (*big)
	{
		if (*big == *little)
		{
			i = (void *)big + 1;
			x = (void *)little + 1;
			while (*i && *x && *i == *x)
			{
				++i;
				++x;
			}
			if (!*x)
				return ((void *)big);
		}
		big++;
	}
	return (NULL);
}
