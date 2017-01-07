/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:41:03 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/29 20:16:00 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

t_list	*mem_alloc(void)
{
	char	*buf;
	t_list	*new;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf)
		return (NULL);
	new = ft_lstnew(buf, BUFF_SIZE + 1);
	if (!new)
		return (NULL);
	return (new);
}

void	read_from_buf(t_line *add, char *str)
{
	char *buf;

	buf = ft_strchr(add->buf, '\n') + 1;
	ft_bzero(str, BUFF_SIZE);
	ft_strlcat(str, buf, BUFF_SIZE);
	free(add->buf);
	add->buf = NULL;
}

int		read_line(t_line *add, int fd)
{
	int		i;
	t_list	*p;

	i = 65535;
	p = mem_alloc();
	if (!p) return (-1);
	add->head = p;
	while (i > 0)
	{
		if (add->buf == NULL)
			i = read(fd, p->content, BUFF_SIZE);
		else
			read_from_buf(add, p->content);
		if ((size_t)ft_lentoc(p->content, '\n') != ft_strlen(p->content))
			break ;
		add->len++;
		p->next = mem_alloc();
		if (!p->next) return (-1);
		p = p->next;
	}
	p->next = NULL;
	return (i);
}

int		write_to_line(t_line *add, char **line)
{
	int		len;
	t_list	*p;
	t_list	*buf;
	
	p = add->head;
	len = 0;
	while (p)
	{
		len = len + ft_lentoc(p->content, '\n');
		p = p->next;
	}
	p = add->head;
	*line = ft_strnew(len);
	if (*line == NULL) return -1;
	ft_bzero(*line, len + 1);
	while (p)
	{
		ft_strlcat(*line, p->content, len + 1);
		if (!p->next) break ;
		buf = p;
		p = p->next;
	}
	add->buf = p->content;
	p->content = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				f;
	static t_line	*add;

	f = 1;
	if (BUFF_SIZE < 0 || BUFF_SIZE > 65534)
		return (-1);
	if (!add)
	{
		add = (t_line*)malloc(sizeof(t_line) * 7164);
		if (!add)
			return (-1);
		ft_bzero((void*)add, 7164);
	}
	f = read_line(&add[fd], fd);
	if (f == -1)
		return (-1);
	if (write_to_line(&add[fd], line) == -1)
		return (-1);
	if (f == 0)
		return (0);
	return (1);
}
