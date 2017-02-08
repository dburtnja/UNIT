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

void	write_non_p(unsigned char **pp, unsigned char *str)
{
	unsigned char	*p;

	p = *pp;
	*p = '^';
	p++;
	*p = *str + '@';
	p++;
	*pp = p;
}

char	*change_str(char *str)
{
	char	*ret;
	char	*p;

	ret = ft_strnew(ft_strlen(str) * 2);
	p = ret;
	while (*str != 0)
	{
		if (*str >= 32 && *str <= 126)
		{
			*p = *str;
			p++;
		}
		else
		{
			write_non_p((unsigned char**)&p, (unsigned char*)str);
		}
		str++;
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
		str = change_str(str);
		mod_m_flag(str, head);
		ft_strdel(&str);
	}
}
