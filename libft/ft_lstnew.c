/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 20:55:20 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/14 20:55:22 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	void	*x;
	t_list	*list;

	if (!(x = ft_memalloc(content_size + 1)))
		return (NULL);
	if (!content)
	{
		x = NULL;
		content_size = 0;
	}
	else
		ft_memcpy(x, content, content_size);
	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	list->content = x;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
