/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:32:52 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/11 21:44:38 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		mk_sign_d(long double *value, t_arg *head, int *len)
{
	*len = 0;
	if (*value < 0)
	{
		(*len)++;
		(*value) *= -1;
		return ('-');
	}
	else if (head->flag.pl == 1)
	{
		(*len)++;
		return ('+');
	}
	else if (head->flag.space == 1)
	{
		(*len)++;
		return (' ');
	}
	else
		return (0);
}

char		*all_len(int *len, t_arg *head, int power_s)
{
	len[3] = 0;
	len[2] = (head->type == 17 || head->type == 18) ? 2 : 0;
	len[6] = head->precision;
	len[5] = (len[6] > 0 || head->flag.hesh == 1) ? 1 : 0;
	len[7] = power_s > 0 ? 2 : 0;
	len[8] = power_s;
	len[0] = len[1] + len[2] + len[4] + len[5] + len[6] + len[7] + len[8];
	if (head->flag.nul == 1 && head->width > len[0] && head->flag.min == 0)
	{
		len[3] = head->width - len[0];
		len[0] = head->width;
	}
	return (ft_strnew(len[0]));
}

char		*make_str(t_arg *head, long double value, int power_s, char hesh)
{
	char		sign;
	int			len[9];
	char		*str;
	char		*s;
	long long	r_nbr;

	r_nbr = (long long)value < 0 ? value * -1 : value;
	sign = mk_sign_d(&value, head, &len[1]);
	len[4] = ft_nbrlen(r_nbr, 10);
	str = all_len(&len[0], head, power_s == 0 || power_s > 2 ? power_s : 2);
	s = str;
	str = add_nul(str, sign, len[3] + len[1], hesh);
	nbr_to_str(r_nbr, 10, &str, 0);
	if (len[5] == 1)
	{
		*str = '.';
		str++;
	}
	if (len[6] > 0 && len[6] <= 15)
		ft_round_d((value < 0 ? value * -1 : value) - (long double)r_nbr,
				head, str);
	else
		ft_round((value < 0 ? value * -1 : value) - (long double)r_nbr,
				head, str);
	return (s);
}

char		*ft_itoa_d(long double value, t_arg *head, int power)
{
	char				*str;

	if (head->precision == 0)
		value = ft_r_nbr(value);
	str = make_str(head, value, power != -1 ? ft_nbrlen((long long)power, 10) :
			0, 0);
	return (str);
}
