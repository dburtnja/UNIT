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
	char	*buf;
	char	*str1;
	char	*str2;
	char	*ret;
	char	upper;

	upper = 'E';
	if (head->type == 13 || head->type == 15)
		upper = 'e';
	str2 = ft_strnew(10);
	str2[0] = upper;
	str2[1] = c < 0 ? '-' : '+';
	buf = str2 + 2;
	if ((c > 0 ? c : c * -1) < 10)
	{
		*buf = '0';
		buf++;
	}
	nbr_to_str(c > 0 ? c : c * -1, 10, &buf, 0);
	str1 = ft_itoa_d(nbr, head, c < 0 ? -c : c);
	ret = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (ret);
}

char	*mod_e(long double nbr, t_arg *head)
{
	unsigned long long	buf;
	int					count;
	long double			r_nbr;

	count = 0;
	buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	while (buf == 0 && nbr != 0)
	{
		count--;
		nbr *= 10;
		buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	}
	while (buf > 9)
	{
		count++;
		nbr /= 10;
		buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	}
	r_nbr = head->precision == 0 ? ft_r_nbr(nbr) : nbr;
	return (write_e(nbr, head, count));
}


char	*mod_g(long double nbr, t_arg *head)
{
	char				*m_d;
	char				*m_e;
	int					buf;
	long double			b_nbr;

	b_nbr = nbr;
	if (head->precision == -1 && nbr == 0)
		head->precision = 0;
	else if (head->precision == -1)
	{
			buf = (int)nbr;
		while (buf == 0)
		{
			nbr *= 10;
			buf = (int)nbr;
		}
		while (buf != 0 && head->precision < 5)
		{
			nbr *= 10;
			head->precision += 1;
			buf = (int)nbr;
			nbr = nbr - (long double)buf;
		}
	}
	m_d = ft_itoa_d(b_nbr, head, -1);
	m_e = mod_e(b_nbr, head);
	if (ft_strlen(m_d) < ft_strlen(m_e))
		return (m_d);
	else
		return (m_e);
}


char	*type_d(t_arg *head, long double nbr)
{
	if (head->type == 11 || head->type == 12)
		return (ft_itoa_d(nbr, head, -1));
	else if (head->type == 13 || head->type == 14)
		return (mod_e(nbr, head));
	else if (head->type == 15 || head->type == 16)
		return (mod_g(nbr, head));
	else if (head->type == 17 || head->type == 18)
		return (mod_a(nbr, head));
	return (NULL);
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
	if (head->precision == -1 && !(head->type >= 15 && head->type <= 18))
		head->precision = 6;
	str = type_d(head, nbr);
	mod_m_flag(str, head);
	ft_strdel(&str);
}
