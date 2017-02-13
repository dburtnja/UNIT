/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:54:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/12 23:20:10 by dburtnja         ###   ########.fr       */
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

char	*add_nul(char *str, char sign, int len, char hesh)
{
	int		i;

	i = 0;
	if (sign != 0)
	{
		*str = sign;
		str++;
		i++;
	}
	if (hesh != 0)
	{
		*str = '0';
		str[1] = hesh;
		str += 2;
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
		len = len + head->precision;
	else if (head->precision == -1 && head->width > nbrl && head->flag.nul == 1)
		len = head->width;
	else
		len = len + nbrl;
	if ((str = ft_strnew(len)) == NULL)
		exit(1);
	s = str;
	str = add_nul(str, sign, len - nbrl, 0);
	if (value == 0 && head->precision == 0)
		*str = '\0';
	else
		nbr_to_str(value, 10, &str, 0);
	return (s);
}
/*
char	*find_size(t_arg *head, int *nbrl, int *len, int val)
{
	if (head->precision == 0 && val && head->type > 5 && head->type < 10)
		return (ft_strnew(*len = 0));
	else if (head->precision > nbrl[1])
		return (ft_strnew(*len = head->precision + nbrl[0]));
	else if (head->precision == -1 && head->width > nbrl[0] + nbrl[1]
&& head->flag.nul == 1)
		return (ft_strnew(*len = head->width));
	else if (head->precision <= nbrl[1] && head->flag.hesh == 1 &&
head->type == 4)
		return (ft_strnew(*len = nbrl[0] + nbrl[1] + 1));
	else
		return (ft_strnew(*len = nbrl[0] + nbrl[1]));
}
*/
char	*find_size(int *len, t_arg *head, int val)
{
	int		f;

	f = head->flag.nul == 1 && head->flag.min == 0 && head->precision < 0;
	len[1] = 0;
	if ((head->flag.hesh == 1 && val != 0) || head->type == 23)
	{
		if (len[4] == 8 && head->precision <= len[3])
			len[1] = 1;
		else if (len[4] == 16)
			len[1] = 2;
	}
	len[0] = len[1] + len[3];
	if (head->precision > len[3])
	{
		len[2] = head->precision - len[3];
		len[0] = len[1] + len[2] + len[3];
	}
	else if (f && head->width > len[0])
	{
		len[2] = head->width - len[0];
		len[0] = head->width;
	}
	return (ft_strnew(len[0]));
}

char	*ft_itoa_u(unsigned long long value, unsigned long long b,
t_arg *head, int up)
{
	int		len[5];
	char	*s;
	char	*str;

	len[2] = 0;
	len[3] = ft_nbrlen(value, b);
	len[4] = b;
	if ((str = find_size(&len[0], head, value)) == NULL)
		exit(1);
	s = str;
	if (len[1] > 0)
		str = add_hesh(str, b, up);
	str = add_nul(str, 0, len[2], 0);
	if (b == 8 && value == 0 && head->precision == 0 && head->flag.hesh == 1)
	{
		*str = '0';
		str++;
	}
	if (value == 0 && head->precision == 0)
		*str = '\0';
	else
		nbr_to_str(value, b, &str, up);
	return (s);
}
