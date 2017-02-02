/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/02 20:25:11 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mod_f(t_arg *head, va_list arg)
{
	char		*str;
	long double	nbr;

	if (head->size == 8)
		nbr = (long double)va_arg(arg, double);
	else
		nbr = va_arg(arg, double);
	if (head->flag.min == 1)
		head->flag.nul = 0;
	if (head->precision == -1)
		head->precision = 6;
	str = ft_itoa_d(nbr, head);
	mod_m_flag(str, head);
	ft_strdel(&str);
}

void	mod_double(t_arg *head, va_list arg)
{
	if (head->type == 11 || head->type == 12)
		mod_f(head, arg);
/*	else if (head->type == 13 || head->type == 14)
		mod_e(head, arg);
	else if (head->type == 15 || head->type == 16)
		mod_g(head, arg);
	else if (head->type == 17 || head->type == 17)
		mod_a(head, arg);	*/
}
