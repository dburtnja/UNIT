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

int		ft_print(t_arg *head)
{
	size_t	len;
	t_arg	*p;

	len = 0;
	while (head)
	{
		if (head->mod != 2)
		{
			len = len + head->len;
			write(1, head->data, head->len);
			ft_strdel(&(head->data));
		}
		else
			write_to_n(head, len);
		p = head;
		head = head->next;
		ft_memdel((void**)&p);
	}
	return (len);
}
