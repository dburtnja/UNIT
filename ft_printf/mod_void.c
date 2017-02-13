/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_void.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:21:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/12 23:20:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_void(unsigned long long value, t_arg *head)
{
	int		len[5];
	char	*s;
	char	*str;

	len[2] = 0;
	len[3] = ft_nbrlen(value, 16);
	len[4] = 16;
	if ((str = find_size(&len[0], head, value)) == NULL)
		exit(1);
	s = str;
	str = add_hesh(str, 16, 0);
	str = add_nul(str, 0, len[2], 0);
	if (value == 0 && head->precision == 0)
		*str = 0;
	else
		nbr_to_str(value, 16, &str, 0);
	return (s);
}

void	mod_void(t_arg *head, va_list ptr)
{
	char				*str;
	unsigned long long	ad;

	head->flag.hesh = 1;
	head->flag.pl = 0;
	head->flag.space = 0;
	if (head->flag.min == 1)
		head->flag.nul = 0;
	ad = (unsigned long long)va_arg(ptr, void*);
	str = ft_itoa_void(ad, head);
	mod_m_flag(str, head);
	ft_strdel(&str);
}
