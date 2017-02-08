/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_mod_m_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:01:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 15:01:57 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_hesh(char *str, int b, int up)
{
	if (b == 16)
	{
		*str = '0';
		str++;
		*str = up == 1 ? 'X' : 'x';
		str++;
	}
	if (b == 8)
	{
		*str = '0';
		str++;
	}
	return (str);
}

size_t	find_len(size_t strl, t_arg head)
{
	int		p;

	p = head.precision;
	if (p != -1 && (size_t)p < strl && (head.type == 21 || head.type == 22))
		return (p);
	return (strl);
}

size_t	find_size_str(size_t strl, t_arg *head, size_t *len)
{
	size_t	ret;

	strl = head->len != 0 ? head->len : strl;
	*len = find_len(strl, *head);
	if (head->width != -1 && *len < (size_t)head->width)
		ret = (size_t)head->width;
	else
		ret = *len;
	head->len = ret;
	return (ret);
}
