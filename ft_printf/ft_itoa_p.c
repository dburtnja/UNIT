/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:54:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 17:12:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	mk_sign(long long *value, t_arg *head, int *len)
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

char	*add_nul(char *str, char sign, int len)
{
	int		i;

	i = 0;
	if (sign != 0)
	{
		*str = sign;
		str++;
		i++;
	}
	while (len > i)
	{
		*str = '0';
		str++;
		i++;
	}
	return (str);
}

char	*ft_itoa_p(long long value, t_arg *head)
{
	int		len;
	char	sign;
	int		nbrl;
	char	*s;
	char	*str;

	sign = mk_sign(&value, head, &len);
	nbrl = ft_nbrlen(value, 10);
	if (head->precision > nbrl)
		str = ft_strnew(len = len + head->precision);
	else if (head->precision == -1 && head->width > nbrl && head->flag.nul == 1)
		str = ft_strnew(len = head->width);
	else
		str = ft_strnew(len = len + nbrl);
	if (!str)
		exit (1);
	s = str;
	str = add_nul(str, sign, len - nbrl);
	nbr_to_str(value, 10, &str, 0);
	return (s);
}
