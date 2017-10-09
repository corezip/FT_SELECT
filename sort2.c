/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:26:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/04/10 16:26:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			**matrix_sort(t_top *x, char **matrix)
{
	x->type.flag = 1;
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while (matrix[x->type.j] != NULL)
		{
			if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
					matrix[x->type.j + 1]) > 0)
			{
				ft_swapchar(&matrix[x->type.j], &matrix[x->type.j + 1]);
				x->type.flag++;
			}
			x->type.j++;
		}
		x->type.j = 0;
	}
	return (matrix);
}

char			**matrix_sort_reverse(t_top *x, char **matrix)
{
	x->type.flag = 1;
	while (x->type.flag != 0)
	{
		x->type.flag = 0;
		while (matrix[x->type.j] != NULL)
		{
			if (matrix[x->type.j + 1] && ft_strcmp(matrix[x->type.j],
					matrix[x->type.j + 1]) < 0)
			{
				ft_swapchar(&matrix[x->type.j], &matrix[x->type.j + 1]);
				x->type.flag++;
			}
			x->type.j++;
		}
		x->type.j = 0;
	}
	return (matrix);
}

int				get_file_error(struct stat filestat, char *file)
{
	if (security_path(file) == 0)
		return (0);
	if (stat(file, &filestat) < 0)
	{
		perror("Error: ");
		return (0);
	}
	return (1);
}
