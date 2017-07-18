/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:17:37 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/17 16:17:38 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*maplist;

	maplist = NULL;
	if (f)
	{
		while (lst)
		{
			ft_lstaddend(&maplist, f(lst));
			lst = lst->next;
		}
	}
	return (maplist);
}
