/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_and_put_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:06:19 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 18:39:10 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_hesh(char *str, size_t *i, int hesh)
{
	if (hesh == 1)
	{
		str[*i] = '0';
		str[(*i) + 1] = 'x';
		*i += 2;
	}
}

size_t	find_len(size_t strl, t_arg head)
{
	int		p;
	int		f_hesh;

	p = head.precision;
	if (head.flag.hesh == 1)
		return (strl + f_hesh);
	if (p != -1 && p < strl)
		return ((size_t)p);
	return (strl);
}

char	*cpy_and_put_char(char *str, t_arg *head)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = find_len(ft_strlen(str), *head);
	ret = ft_strnew(len > head->width ? len : head->width);
	i = 0;
	add_hesh(ret, &i, head->flag.hesh);
	while (i < len)
	{
		ret[i] = *str;
		str++;
		i++;
	}
	while (i < head->width)
	{
		ret[i] = ' ';
		i++;
	}
	return (ret);
}

char	*put_char_and_cpy(char *str, t_arg *head)
{
	size_t	len;
	size_t	w;
	size_t	i;
	char	*ret;

	len = find_len(ft_strlen(str), *head);
	w = (int)len > head->width ? len : head->width;
	ret = ft_strnew(w);
	i = 0;
	while (i < w - len)
	{
		ret[i] = ' ';
		i++;
	}
	add_hesh(ret, &i, head->flag.hesh);
	while (i < w)
	{
		ret[i] = *str;
		i++;
		str++;
	}
	return (ret);
}

void	mod_m_flag(char *str, t_arg *head)
{
	if (head->flag.min == 1)
		head->data = cpy_and_put_char(str, head);
	else
		head->data = put_char_and_cpy(str, head);
}
