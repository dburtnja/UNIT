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

t_arg	*read_str(char *str)
{
	t_arg	*head;
	t_arg	*p;
	int		start;

	start = 0;
	head = NULL;
	p = NULL;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			p = check_type(&str);
			colect_lst(&head, p);
		}
		else
		{
			p = new_lst(ft_strsub(str, 0, ft_lentoc(str, '%')), 0);
			colect_lst(&head, p);
			str = str + ft_lentoc(str, '%');
		}
	}
	return (head);
}
