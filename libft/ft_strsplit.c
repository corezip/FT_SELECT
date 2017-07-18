/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:35:53 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/13 16:35:54 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		words;
	size_t	element;

	index = 0;
	element = 0;
	words = ft_wordcount(s, c);
	str = (char **)ft_memalloc(sizeof(char *) * (words + 1));
	if (!str)
		return (0);
	while (index < words)
		str[index++] = ft_nextword(s, c, &element);
	str[index] = 0;
	return (str);
}
