/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 19:16:21 by gsolis            #+#    #+#             */
/*   Updated: 2017/08/21 19:16:24 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		extra_key(t_var *x , long key)
{
	if (key == KEY_R)
	{
		x->objects = x->ar;
	}
}

void		get_ar(int ac, char **ar, t_var *x)
{
	int		i;

	i = -1;

	x->ar = (char**)malloc(sizeof(char*) * ac);
	while(ar[++i])
		x->ar[i] = ft_strdup(ar[i]);
}
