/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_i_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:45:20 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:03:22 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	d_type(va_list arg, t_arg *head)
{
	if (head->size == 0)
		return ((long long)va_arg(arg, long));
	else if (head->size == 1)
	{
		return ((long long)va_arg(arg, int));
	}
	else if (head->size == 2)
	{
		return (long long)va_arg(arg, int);
	}
	else if (head->size == 3)
		return ((long long)va_arg(arg, long));
	else if (head->size == 4)
		return (va_arg(arg, long long));
	else if (head->size == 5)
		return ((long long)va_arg(arg, intmax_t));
	return ((long long)va_arg(arg, size_t));
}

long long	r_type(va_list arg, t_arg *head)
{
	signed char	c;
	short int	s_i;

	if (head->size == 0)
		return ((long long)va_arg(arg, int));
	else if (head->size == 1)
	{
		c = (signed char)va_arg(arg, int);
		return ((long long)c);
	}
	else if (head->size == 2)
	{
		s_i = (short int)va_arg(arg, int);
		return ((long long)s_i);
	}
	else if (head->size == 3)
		return ((long long)va_arg(arg, long));
	else if (head->size == 4)
		return (va_arg(arg, long long));
	else if (head->size == 5)
		return ((long long)va_arg(arg, intmax_t));
	return ((long long)va_arg(arg, size_t));
}

void		mod_int(t_arg *head, va_list arg)
{
	char		*str;
	long long	nbr;

	if (head->flag.min == 1)
		head->flag.nul = 0;
	head->flag.hesh = 0;
	if (head->type == 2)
		nbr = d_type(arg, head);
	else
		nbr = r_type(arg, head);
	str = ft_itoa_p(nbr, head);
	head->precision = -1;
	mod_m_flag(str, head);
	ft_strdel(&str);
}

void		mod_i_d(t_arg *head, va_list arg)
{
	if (head->size < 7)
		mod_int(head, arg);
}
