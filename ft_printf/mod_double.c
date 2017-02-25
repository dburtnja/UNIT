/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/16 14:35:35 by dburtnja         ###   ########.fr       */
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

	upper = head->type == 13 || head->type == 15 ? 'e' : 'E';
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

char	*mod_e(long double nbr, t_arg *head, int *count)
{
	unsigned long long	buf;
	long double			r_nbr;

	*count = 0;
	buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	while (buf == 0 && nbr != 0)
	{
		(*count)--;
		nbr *= 10;
		buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	}
	while (buf > 9)
	{
		(*count)++;
		nbr /= 10;
		buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	}
	r_nbr = head->precision == 0 ? ft_r_nbr(nbr) : nbr;
	return (write_e(nbr, head, *count));
}

char	*type_d(t_arg *head, long double nbr)
{
	int		count;

	if (head->type == 11 || head->type == 12)
		return (ft_itoa_d(nbr, head, -1));
	else if (head->type == 13 || head->type == 14)
		return (mod_e(nbr, head, &count));
	else if (head->type == 15 || head->type == 16)
		return (mod_g(nbr, head));
	else if (head->type == 17 || head->type == 18)
		return (mod_a(nbr, head));
	return (NULL);
}

char	*other_nbr(long double nbr, t_arg *head)
{
	char		*str;
	int			up;

	str = NULL;
	up = head->type % 2 == 0;
	if (nbr != nbr)
		str = up ? ft_strdup("NAN") : ft_strdup("nan");
	else if (nbr == -0.1 / 0)
		str = up ? ft_strdup("-INF") : ft_strdup("-inf");
	else if (nbr == 0.1 / 0)
		str = up ? ft_strdup("INF") : ft_strdup("inf");
	return (str);
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
	if ((str = other_nbr(nbr, head)) == NULL)
		str = type_d(head, nbr);
	mod_m_flag(str, head);
	ft_strdel(&str);
}
