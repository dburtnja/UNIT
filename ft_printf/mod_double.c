/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:18:58 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_e(long double nbr, t_arg *head, int c)
{
	char	*str1;
	char	*str2;
	char	*ret;
	char	upper;

	upper = 'E';
	if (head->type == 13 || head->type == 15)
		upper = 'e';
	str1 = ft_itoa_d(nbr, head);
	str2 = ft_strnew(4);
	str2[0] = upper;
	str2[1] = c < 0 ? '-' : '+';
	c = c > 0 ? c : c * -1;
	str2[2] = c / 10 + '0';
	str2[3] = c % 10 + '0';
	ret = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (ret);
}

char	*mod_e(long double nbr, t_arg *head)
{
	unsigned long long	buf;
	int					count;

	count = 0;
	buf = (long long)nbr;
	while (buf == 0)
	{
		count--;
		nbr *= 10;
		buf = (unsigned long long)nbr;
	}
	while (buf > 9)
	{
		count++;
		nbr /= 10;
		buf = (unsigned long long)nbr;
	}
	return (write_e(nbr, head, count));
}

/*
char	*mod_g(long double nbr, t_arg *head)
{
	unsigned long long	buf;

	head->precision = head->precision > 1 ? head->precision : 1;
	buf = (unsigned long long)nbr;
	if (buf < 0)
	{
		
	}
}
*/

char	*type_d(t_arg *head, long double nbr)
{
	if (head->type == 11 || head->type == 12)
		return (ft_itoa_d(nbr, head));
	else if (head->type == 13 || head->type == 14)
		return (mod_e(nbr, head));
	/*else if (head->type == 15 || head->type == 16)
		return (mod_g(nbr, head));
*/	/*else if (head->type == 17 || head->type == 18)
		mod_a(head, arg);
*/	return (NULL);
}

void	mod_double(t_arg *head, va_list arg)
{
	char		*str;
	long double	nbr;

	if (head->size == 8)
		nbr = (long double)va_arg(arg, long double);
	else
		nbr = va_arg(arg, double);
	if (head->flag.min == 1)
		head->flag.nul = 0;
	if (head->precision == -1)
		head->precision = 6;
	str = type_d(head, nbr);
	mod_m_flag(str, head);
	ft_strdel(&str);
}
