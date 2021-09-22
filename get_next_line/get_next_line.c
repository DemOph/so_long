/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:42:07 by chael-ha          #+#    #+#             */
/*   Updated: 2021/04/26 17:46:23 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

void				my_del(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

int					next_line(char **whtsleft, char **line)
{
	int				j;
	char			*tmp;

	j = 0;
	while ((*whtsleft)[j] != '\n' && (*whtsleft)[j])
		j++;
	if ((*whtsleft)[j] == '\n')
	{
		*line = ft_substr(*whtsleft, 0, j);
		tmp = ft_strdup(&((*whtsleft)[j + 1]));
		free(*whtsleft);
		*whtsleft = tmp;
		if ((*whtsleft)[0] == '\0')
			my_del(whtsleft);
	}
	else
	{
		*line = ft_strdup(*whtsleft);
		my_del(whtsleft);
		return (0);
	}
	return (1);
}

int					read_test(int i, int fd, char **str, char **line)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && !str[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	return (next_line(&str[fd], line));
}

int					get_next_line(int fd, char **line)
{
	int				i;
	char			*buffer;
	static char		*whtsleft[256];
	char			*s;

	if (fd < 0 || !line || 32 < 0 || fd > 256)
		return (-1);
	if (!(buffer = (char *)malloc(32 + 1)))
		return (-1);
	while ((i = read(fd, buffer, 32)) > 0)
	{
		buffer[i] = '\0';
		if (!whtsleft[fd])
			whtsleft[fd] = ft_strdup(buffer);
		else
		{
			s = ft_strjoin(whtsleft[fd], buffer);
			free(whtsleft[fd]);
			whtsleft[fd] = s;
		}
		if (ft_strchr(whtsleft[fd], '\n'))
			break ;
	}
	free(buffer);
	return (read_test(i, fd, whtsleft, line));
}
