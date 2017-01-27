/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_i_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:45:20 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 20:28:42 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	r_type(va_list arg, t_arg *head)
{
	if (head->size < 3)
		return ((long long)va_arg(arg, int));
	else if (head->size == 3)
		return ((long long)va_arg(arg, long int));
	else if (head->size == 4)
		return ((long long)va_arg(arg, long long int));
	return (-1);
}

void		mod_int(t_arg *head, va_list arg)
{
	char	*str;

	if (head->flag.min == 1)
		head->flag.nul = 0;
	head->flag.hesh = 0;
	str = ft_itoa_p(r_type(arg, head), head);
	head->precision = -1;
	mod_m_flag(str, head);
	ft_strdel(&str);
}

void		mod_i_d(t_arg *head, va_list arg)
{
	if (head->size < 5)
		mod_int(head, arg);	
}
