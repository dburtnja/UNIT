/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_void.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:21:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:21:16 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_void(t_arg *head, va_list ptr)
{
	char				*str;
	char				*buf;
	unsigned long long	ad;

	head->flag.hesh = 0;
	head->flag.pl = 0;
	head->flag.space = 0;
	if (head->flag.min == 1)
		head->flag.nul = 0;
	ad = (unsigned long long)va_arg(ptr, void*);
	if (ad == 0 && head->precision == 0)
	{
		str = "0x";
		mod_m_flag(str, head);
	}
	else
	{
		buf = ft_itoa_u(ad, 16, head, 0);
		str = ft_strjoin("0x", buf);
		ft_strdel(&buf);
		mod_m_flag(str, head);
		ft_strdel(&str);
	}
}
