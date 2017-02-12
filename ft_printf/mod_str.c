/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:17:10 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/12 19:03:48 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_wchar_t(va_list ptr, t_arg *head)
{
	int		i;
	int		*str;
	char	*ret;
	char	*buf;
	char	*n_str;

	i = 0;
	buf = ft_strnew(0);
	str = va_arg(ptr, int*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	while (*str != 0)
	{
		n_str = check_char(*str);
		i += ft_strlen(n_str);
		if (head->precision != -1 && i > head->precision)
			break ;
		ret = ft_strjoin(buf, n_str);
		ft_strdel(&buf);
		ft_strdel(&n_str);
		buf = ret;
		str++;
	}
	return (buf);
}

void	mod_str(t_arg *head, va_list ptr)
{
	char	*str;

	head->flag.hesh = 0;
	if (head->size == 3 || head->type == 22)
	{
		str = read_wchar_t(ptr, head);
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
