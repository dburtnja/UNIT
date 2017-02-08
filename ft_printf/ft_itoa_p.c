/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:54:14 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:11:20 by dburtnja         ###   ########.fr       */
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
		len = len + head->precision;
	else if (head->precision == -1 && head->width > nbrl && head->flag.nul == 1)
		len = head->width;
	else
		len = len + nbrl;
	if ((str = ft_strnew(len)) == NULL)
		exit(1);
	s = str;
	str = add_nul(str, sign, len - nbrl);
	if (value == 0 && head->precision == 0)
		*str = '\0';
	else
		nbr_to_str(value, 10, &str, 0);
	return (s);
}

char	*find_size(t_arg *head, int nbrl, int *len, int val)
{
	if (head->precision == 0 && val && head->type > 5 && head->type < 10)
		return (ft_strnew(*len = 0));
	else if (head->precision > nbrl)
		return (ft_strnew(*len = head->precision));
	else if (head->precision == -1 && head->width > nbrl && head->flag.nul == 1)
		return (ft_strnew(*len = head->width));
	else if (head->precision <= nbrl && head->flag.hesh == 1 && head->type == 4)
		return (ft_strnew(*len = nbrl + 1));
	else
		return (ft_strnew(*len = nbrl));
}

char	*ft_itoa_u(unsigned long long value, unsigned long long b,
t_arg *head, int up)
{
	int		len;
	int		nbrl;
	char	*s;
	char	*str;

	nbrl = ft_nbrlen(value, b);
	if (head->flag.hesh == 1 && !(value == 0 && b != 8))
	{
		if (b == 8)
			nbrl++;
		else if (b == 16)
			nbrl += 2;
	}
	if ((str = find_size(head, nbrl, &len, value == 0)) == NULL)
		exit(1);
	s = str;
	if (head->flag.hesh == 1 && !(value == 0 && b != 8))
		str = add_hesh(str, b, up);
	str = add_nul(str, 0, len - nbrl);
	if (value == 0 && head->precision == 0)
		*str = '\0';
	else
		nbr_to_str(value, b, &str, up);
	return (s);
}
