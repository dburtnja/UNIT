/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:04:21 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/12 18:54:44 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_char(int c)
{
	char	*str;

	if (c == 0)
		return (ft_strdup("\0"));
	if (c < 128)
	{
		if ((str = ft_strnew(1)) == NULL)
			exit(1);
		str[0] = (char)c;
		return (str);
	}
	else if (c < 2048)
	{
		str = proc_wint8(c);
		return (str);
	}
	return (proc_wint16(c));
}

void	mod_char(t_arg *head, va_list ptr, char c)
{
	char	*str;

	head->len = 1;
	head->precision = -1;
	if (c != 0)
		str = ft_strdup("%");
	else if (head->size == 3)
	{
		str = check_char(va_arg(ptr, int));
		head->len = head->len < ft_strlen(str) ? ft_strlen(str) : head->len;
	}
	else
	{
		if ((str = ft_strnew(1)) == NULL)
			exit(1);
		str[0] = (char)va_arg(ptr, int);
	}
	mod_m_flag(str, head);
	ft_strdel(&str);
}
