/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:20:46 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:20:51 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_non_p(unsigned char **pp, unsigned char c)
{
	unsigned char	*p;

	p = *pp;
	if (c > 127 && c < 160)
	{
		c = c - 128;
		*p = 'M';
		p++;
		*p = '-';
		p++;
	}
	*p = '^';
	p++;
	if (c == 127)
		*p = '?';
	else
		*p = c + '@';
	p++;
	*pp = p;
}

char	*change_str(char *str, int len)
{
	char	*ret;
	char	*p;

	ret = ft_strnew(ft_strlen(str) * 4);
	p = ret;
	while (len > 0)
	{
		if ((*str >= 32 && *str <= 126) || (unsigned char)*str > 160)
		{
			*p = *str;
			p++;
		}
		else
		{
			write_non_p((unsigned char**)&p, (unsigned char)*str);
		}
		str++;
		len--;
	}
	return (ret);
}

void	mod_r(t_arg *head, va_list arg)
{
	char	*str;

	str = va_arg(arg, char*);
	head->flag.hesh = 0;
	if (str == NULL)
		mod_m_flag("(null)", head);
	else
	{
		str = change_str(str, head->precision);
		mod_m_flag(str, head);
		ft_strdel(&str);
	}
}
