/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:17:10 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/10 21:24:47 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_wchar_t(va_list ptr)
{
	int		*str;
	char	*ret;
	char	*buf;
	char	*new;

	buf = ft_strnew(0);
	str = va_arg(ptr, int*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	while (*str != 0)
	{
		new = check_char(*str);
		ret = ft_strjoin(buf, new);
		ft_strdel(&buf);
		ft_strdel(&new);
		buf = ret;
		str++;
	}
	return (ret);
}

void	mod_str(t_arg *head, va_list ptr)
{
	char	*str;

	head->flag.hesh = 0;
	if (head->size == 3)
	{
		str = read_wchar_t(ptr);
		mod_m_flag(str, head);
		ft_strdel(&str);
	}
	else
	{
		str = va_arg(ptr, char*);
		if (str == NULL)
			mod_m_flag("(null)", head);
		else
			mod_m_flag(str, head);
	}
}
