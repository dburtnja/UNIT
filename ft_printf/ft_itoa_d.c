/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:26:22 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:02:03 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*all_len(int *len, t_arg *head)
{
	len[2] = 0;
	len[4] = 0;
	len[5] = head->precision;
	if (head->precision > 0)
		len[4] = 1;
	else if (head->flag.hesh == 1)
		len[4] = 1;
	len[0] = len[1] + len[3] + len[4] + len[5];
	if (head->flag.nul == 1 && head->width > len[0] && head->flag.min == 0)
	{
		len[2] = head->width - len[0];
		len[0] = head->width;
	}
	return (ft_strnew(len[0]));
}

char		*make_str(long long r_nbr, t_arg *head, long double value)
{
	char	sign;
	int		len[6];
	char	*str;
	char	*s;

	sign = mk_sign(&r_nbr, head, &len[1]);
	len[3] = ft_nbrlen(r_nbr, 10);
	str = all_len(&len[0], head);
	s = str;
	str = add_nul(str, sign, len[2]);
	head->flag.hesh = 0;
	nbr_to_str(r_nbr, 10, &str, 0);
	str = add_nul(str, (len[4] == 1 ? '.' : 0), 0);
	if (len[5] > 0 && len[5] <= 15)
		ft_round_d((value < 0 ? value * -1 : value) - (long double)r_nbr,
				head, str);
	else
		ft_round((value < 0 ? value * -1 : value) - (long double)r_nbr,
				head, str);
	return (s);
}

char		*ft_itoa_d(long double value, t_arg *head)
{
	char				*str;
	long long			r_nbr;

	r_nbr = (long long)value;
	str = make_str(r_nbr, head, value);
	return (str);
}
