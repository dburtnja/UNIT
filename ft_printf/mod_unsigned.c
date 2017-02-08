/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:19:16 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 15:20:31 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	un_type(va_list arg, t_arg *head)
{
	unsigned long long	s_i;

	if (head->size == 0)
		return ((unsigned long long)va_arg(arg, unsigned long));
	else if (head->size == 1)
	{
		return ((unsigned long long)va_arg(arg, unsigned int));
	}
	else if (head->size == 2)
	{
		s_i = (unsigned long long)va_arg(arg, unsigned long);
		return ((unsigned long long)s_i);
	}
	else if (head->size == 3)
		return ((unsigned long long)va_arg(arg, unsigned long));
	else if (head->size == 4)
		return (va_arg(arg, unsigned long long));
	else if (head->size == 5)
		return ((unsigned long long)va_arg(arg, uintmax_t));
	return ((unsigned long long)va_arg(arg, size_t));
}

unsigned long long	ox_type(va_list arg, t_arg *head)
{
	unsigned char		c;
	unsigned short int	s_i;

	if (head->size == 0)
		return ((unsigned long long)va_arg(arg, unsigned int));
	else if (head->size == 1)
	{
		c = (unsigned char)va_arg(arg, unsigned int);
		return ((unsigned long long)c);
	}
	else if (head->size == 2)
	{
		s_i = (unsigned short int)va_arg(arg, unsigned int);
		return ((unsigned long long)s_i);
	}
	else if (head->size == 3)
		return ((unsigned long long)va_arg(arg, unsigned long));
	else if (head->size == 4)
		return (va_arg(arg, unsigned long long));
	else if (head->size == 5)
		return ((unsigned long long)va_arg(arg, uintmax_t));
	return ((unsigned long long)va_arg(arg, size_t));
}

void				mod_unsigned_int(t_arg *head, va_list arg, int b,
int up)
{
	char				*str;
	unsigned long long	nbr;

	head->flag.pl = 0;
	head->flag.space = 0;
	if (head->flag.min == 1)
		head->flag.nul = 0;
	if (head->type == 5 || head->type == 7)
		nbr = un_type(arg, head);
	else
		nbr = ox_type(arg, head);
	if (nbr == 0 && head->precision != 0)
		head->flag.hesh = 0;
	str = ft_itoa_u(nbr, (unsigned long long)b, head, up);
	mod_m_flag(str, head);
	ft_strdel(&str);
}

void				mod_unsigned(t_arg *head, va_list arg)
{
	if (head->type == 4 || head->type == 5)
	{
		head->flag.hesh = 0;
		mod_unsigned_int(head, arg, 10, 0);
	}
	else if (head->type == 6 || head->type == 7)
		mod_unsigned_int(head, arg, 8, 0);
	else if (head->type == 8)
		mod_unsigned_int(head, arg, 16, 0);
	else if (head->type == 9)
		mod_unsigned_int(head, arg, 16, 1);
	else if (head->type == 10)
	{
		head->flag.hesh = 0;
		mod_unsigned_int(head, arg, 2, 0);
	}
}
