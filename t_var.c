/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_var.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:30:46 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/20 18:30:47 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**
** ---------------------------------------------------------------------------
**
*/

void			ft_arr_remove_nth(int nth, void *array, size_t size, int len)
{
	unsigned char	*elem;

	elem = (((unsigned char *)array) + (nth * size));
	ft_memmove((void *)elem, (void *)(elem + size), (len - nth) * size);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

t_var			*saved_env(t_var *env)
{
	static t_var	*setenv;

	if (env)
	{
		setenv = env;
		return (setenv);
	}
	else
	{
		setenv = (t_var *)malloc(sizeof(t_var));
		return (setenv);
	}
}

/*
**
** ---------------------------------------------------------------------------
** Flag == 0 salva la estructura.
** Flag > 0 recupera la estructura.
*/

t_var			*safe_t_var(t_var *x, int flag)
{
	static t_var	*tmp;

	if (flag == 0)
		tmp = x;
	return (tmp);
}
