/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <gsolis@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 18:33:26 by gsolis            #+#    #+#             */
/*   Updated: 2017/07/20 18:33:27 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**
** ---------------------------------------------------------------------------
**
*/

void			ft_cursor_goto(int x, int y)
{
	char		*str1;
	char		*str2;

	if ((str1 = tgetstr("cm", NULL)) != NULL)
	{
		if ((str2 = tgoto(str1, x, y)) != NULL)
			ft_putstr_fd(str2, 2);
	}
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void			mode_str(char *str)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(tgetstr(str, NULL), 2);
}

/*
**
** ---------------------------------------------------------------------------
**
*/

void			ft_clrscreen(int rows)
{
	while (--rows >= 0)
	{
		ft_cursor_goto(0, rows);
		mode_str("dl");
	}
}
