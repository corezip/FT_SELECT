/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeletenode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 18:53:21 by gsolis            #+#    #+#             */
/*   Updated: 2017/06/19 18:53:23 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdeletenode(t_list *e, int nb)
{
	t_list		*tmp;
	t_list		*tmp2;
	int			i;

	i = -1;
	tmp = e;
	if (nb == 1)
	{
		e = tmp->next;
		free(tmp);
		return ;
	}
	while (++i < nb - 2)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	free(tmp2);
}
