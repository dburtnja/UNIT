/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_and_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:59:12 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:00:43 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_to_n(t_arg *head, size_t len)
{
	if (head->size == 0)
		*(head->data) = (int)len;
	else if (head->size == 1)
		*(head->data) = (signed char)len;
	else if (head->size == 2)
		*(head->data) = (short int)len;
	else if (head->size == 3)
		*(head->data) = (long)len;
	else if (head->size == 4)
		*(head->data) = (long long)len;
	else if (head->size == 6)
		*(head->data) = (size_t)len;
}

size_t	find_len_str(t_arg *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (head->mod != 2)
			len = len + head->len;
		else
			write_to_n(head, len);
		head = head->next;
	}
	return (len);
}

void	write_data_to_str(char *from, char **into, size_t len)
{
	char	*buf;

	buf = *into;
	while (len > 0)
	{
		*buf = *from;
		buf++;
		from++;
		len--;
	}
	*into = buf;
}

size_t	collect_str(t_arg *head, char **str)
{
	size_t	len;
	char	*ret;
	t_arg	*p;

	len = find_len_str(head);
	*str = ft_strnew(len);
	ret = *str;
	while (head)
	{
		if (head->mod != 2)
		{
			write_data_to_str(head->data, str, head->len);
			ft_strdel(&(head->data));
		}
		p = head;
		head = head->next;
		ft_memdel((void**)&p);
	}
	*str = ret;
	return (len);
}

int		ft_print(t_arg *head)
{
	size_t	len;
	char	*str;

	len = collect_str(head, &str);
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}
