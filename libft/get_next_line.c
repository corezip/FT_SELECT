/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:50:33 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/23 13:50:34 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_put(char *tmp_str, char **str, char *heap)
{
	*str = ft_strjoin(tmp_str, heap);
}

static int			ft_check(int ret, char **line)
{
	if (!ret && *line)
		*line = NULL;
	return (ret);
}

static int			check_line(char **str, char **line)
{
	char			*tmp_str;
	int				i;

	i = 0;
	if (!(tmp_str = ft_strchr(*str, '\n')))
		return (0);
	*tmp_str = '\0';
	*line = ft_strdup(*str);
	*str = ft_strdup(tmp_str + 1);
	return (1);
}

static	int			read_file(int fd, char *heap, char **str, char **line)
{
	int				ret;
	char			*tmp_str;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*str)
		{
			tmp_str = *str;
			ft_put(tmp_str, str, heap);
		}
		else
			*str = ft_strdup(heap);
		if (check_line(str, line))
			break ;
	}
	return (ret > 0 ? 1 : ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*str[4096];
	char			*heap;
	int				ret;

	if (!line || (fd < 0 || fd > 4096) || (read(fd, str[fd], 0) < 0))
		return (-1);
	if (str[fd])
		if (check_line(&str[fd], line))
			return (1);
	heap = ft_strnew(BUFF_SIZE);
	ft_bzero(heap, BUFF_SIZE);
	ret = read_file(fd, heap, &str[fd], line);
	if (ret != 0 || str[fd] == NULL || str[fd][0] == '\0')
		return (ft_check(ret, line));
	*line = str[fd];
	str[fd] = NULL;
	return (1);
}
