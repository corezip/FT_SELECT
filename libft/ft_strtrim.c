/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:30:05 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/13 14:30:08 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*start;
	char	*end;

	if (!s)
		return (NULL);
	start = (char *)s;
	end = ft_strchr(s, 0) - 1;
	while (whitespace(*start))
		++start;
	while (whitespace(*end) && end > start)
		--end;
	return (ft_strsub(start, 0, 1 + end - start));
}
