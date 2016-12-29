/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:17:04 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/29 22:48:53 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*read_file(const int fd)
{
	int		r;
	char	*buf;
	char	*new;

	new = ft_strnew(BUFF_SIZE);
	if (!new)
		return (NULL);
	r = read(fd, new, BUFF_SIZE);
	buf = ft_strnew(BUFF_SIZE);
	if (!buf)
		return (NULL);
	while (r > 0)
	{
		r = read(fd, buf, BUFF_SIZE);
		if (r == 0)
			return (new);
		new = ft_strjoin(new, buf);
		buf = ft_strnew(BUFF_SIZE);
		if (!buf)
			return (NULL);
	}
	if (r == -1)
		return (NULL);
	else
		return (new);
}

int		get_line(char **str, char **lines)
{
	char	*line;
	char	*s;
	int		i;
	int		j;

	line = *lines;
	s = *str;
	j = 0;
	i = ft_lentoc(s, '\n');
	line = ft_strnew(i);
	if (!line)
		return (-1);
	while (i > j)
	{
		line[j] = *s;
		j++;
		s++;
	}
	if (*s == '\n')
		s++;
	str = &s;
	if (*s == '\0')
		return (0);
	else
	{
		//printf("line = %s str = %s s = %s",line, *str, s);
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;

	if (!(BUFF_SIZE > 0 && BUFF_SIZE < 65534))
		return (-1);
	if (str == NULL)
	{
		str = read_file(fd);
		if (!str)
			return (-1);
	}
	if (get_line(&str, line))
		return (1);
	return (0);
}
