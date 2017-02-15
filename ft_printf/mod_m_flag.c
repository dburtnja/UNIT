/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_m_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:19:12 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/15 21:27:56 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cpy_and_put_char(char *str, t_arg *head)
{
	size_t	len;
	size_t	i;
	char	*ret;

	ret = ft_strnew(find_size_str(ft_strlen(str), head, &len));
	i = 0;
	while (i < len)
	{
		ret[i] = *str;
		str++;
		i++;
	}
	while (head->width > 0 && i < (size_t)head->width)
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

	w = find_size_str(ft_strlen(str), head, &len);
	ret = ft_strnew(w);
	i = 0;
	while (i < w - len)
	{
		ret[i] = head->flag.nul == 1 ? '0' : ' ';
		i++;
	}
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
	if (!((head->type >= 19 && head->type <= 22) || head->type == 27 ||
				head->type == 0))
		head->flag.nul = 0;
	if (head->flag.min == 1)
		head->data = cpy_and_put_char(str, head);
	else
		head->data = put_char_and_cpy(str, head);
}
