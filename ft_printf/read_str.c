/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:02:36 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/19 14:09:29 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*read_str(char *str, va_list arg)
{
	t_arg	*head;
	t_arg	*p;
	int		start;
	size_t	len;

	start = 0;
	head = NULL;
	p = NULL;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			p = check_type(&str, arg);
			colect_lst(&head, p);
		}
		else
		{
			p = new_lst(ft_strsub(str, 0, (len = ft_lentoc(str, '%'))), 0);
			p->len = len;
			colect_lst(&head, p);
			str = str + len;
		}
	}
	return (head);
}
