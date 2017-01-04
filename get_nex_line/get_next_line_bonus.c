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

#include "../libft/libft.h"
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

int		read_line(t_line *add, int fd)
{
	int		i;
	t_list	*p;

	i = 65535;
	add->len = 0;
	p = mem_alloc();
	if (!p) return (-1);
	add->head = p;
	while (i > 0)
	{
		i = read(fd, p->content, BUFF_SIZE);
		if (ft_lentoc(p->content, '\n') != BUFF_SIZE)
			break ;
		add->len++;
		p->next = mem_alloc();
		if (!p->next) return (-1);
		p = p->next;
	}
	add->len = add->len * BUFF_SIZE + ft_lentoc(p->content, '\n');
	p->next = NULL;
	return (i);
}

int		write_to_line(t_line *add, char **line)
{
	int		start;
	t_list	*p;
	char	*buf;

	p = add->head;
	*line = ft_strnew(add->len);
	ft_bzero(*line, add->len + 1);
	while (p)
	{
		ft_strlcat(*line, p->content, add->len + 1);    //free 654544546
		if (!p->next)
			break ;
		p = p->next;
	}
	add->buf_s = BUFF_SIZE - ft_lentoc(p->content, '\n') - 1; 
	start = (ft_strchr(p->content, '\n') - (char*)p->content);
	if (add->buf_s > 0)
		add->buf = ft_strsub(p->content, start + 1, add->buf_s);
	return (1);
}

int		read_from_buf(t_line *add, char **line)
{
	char 	*buf;
	int		len;
	int		size;

	size = 0;
	buf = add->buf;
	len = ft_lentoc(buf, '\n');
	*line = ft_strnew(len);
	ft_strlcat(*line, buf, len + 1);
	if (len < add->buf_s)
	{
		
	}

	add->buf_s = size;
	free(buf)


	if (buf == NULL) ft_putstr("NULL");
	if (len == add->buf_s)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				f;
	static t_line	*add;

	if (BUFF_SIZE < 0 || BUFF_SIZE > 65534)
		return (-1);
	if (!add)
	{
		add = (t_line*)malloc(sizeof(t_line) * 7164);
		if (!add)
			return (-1);
		ft_bzero((void*)add, 7164);
	}
	if (add[fd].buf != NULL)
	{
		ft_putstr("aaaa");
		f = read_from_buf(&add[fd], line);
	}
	if (f > 0)//////
	{
		f = read_line(&add[fd], fd);
		if (f == -1)
			return (-1);
		write_to_line(&add[fd], line);
	}


	//ft_lstiter(add[fd].head, *ft_lstprint_str);
	if (f > 0)
		return (1);
	return (f);
}
