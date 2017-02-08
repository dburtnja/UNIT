/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:08:57 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 16:05:11 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_ceil(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr <= i)
		return (i);
	return (i + 1);
}

long double	ft_floor(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr >= i)
		return (i);
	return (i - 1);
}

char		*ft_round(long double nbr, t_arg *head, char *str)
{
	int			i;
	int			p;

	p = head->precision;
	while (p > 0)
	{
		nbr *= 10;
		if (p == 1)
			nbr = (nbr - ft_floor(nbr) >= 0.5 ? ft_ceil(nbr) : ft_floor(nbr));
		i = (int)nbr;
		*str = i + '0';
		nbr = nbr - i;
		p--;
		str++;
	}
	return (str);
}

void		ft_round_d(long double nbr, t_arg *head, char *str)
{
	int		p;

	p = head->precision;
	while (p > 0)
	{
		nbr *= 10;
		p--;
		if ((int)nbr == 0)
		{
			*str = '0';
			str++;
		}
		else
			break ;
	}
	while (p > 0)
	{
		nbr *= 10;
		p--;
	}
	nbr_to_str(nbr - ft_floor(nbr) >= 0.5 ? ft_ceil(nbr) : ft_floor(nbr), 10,
			&str, 0);
}
