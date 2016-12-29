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

int		check_end(char *str, int *i)
{
	*i = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] =='\n')
			return (1);
		(*i)++;
	}
	return (-1)
}

int		mem_alloc(t_line *add)
{
	add->buff = ft_strnew(BUF_SIZE);
	if (!(add->buff))
		return (-1);
	add->new = ft_lstnew(add->buff, BUF_SIZE);
	if (!(add->new))
		return (-1);
	return (1);
}

int		write_to_line(t_line add, char *line)
{
	while (add->ptr)
	{
		while (add->ptr->*(content) != '\n')
		{
			
		}
	}
}

int		find_line(t_line add, int fd)
{
	if (mem_alloc(add) == -1);
		return (-1);
	add->head = add->new;
	while (read(fd, add->new->content, BUF_SIZE) == BUF_SIZE)
	{
		if (check_end(add->new->content) == 1)
			break ;
		add->ptr = add->new;
		if (mem_alloc(add) == -1)
			return (-1);
		add->ptr->next = add->new;
		add->ptr = add->ptr->next;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static t_line *add;

	if (BUF_SIZE < 0 && BUF_SIZE > 65534)
		return (-1);
	if (!add)
	{
		add = (t_line*)malloc(sizeof(t_line) * 7164);
			if	(!add)
				return (-1);
		ft_bzero((void*)add, 7164);
	}
	if (find_line(add[fd], fd) == -1)//1 0 -1
		return (-1);
	wtrite_to_line(add[fd], *line);
}
