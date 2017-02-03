/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:08:57 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/03 14:57:01 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double			ft_ceil(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr <= i)
		return (i);
	return (i + 1);
}

long double			ft_floor(long double nbr)
{
	long double	i;

	i = (long long)nbr;
	if (nbr >= i)
		return (i);
	return (i - 1);
}

unsigned long long	ft_round(long double nbr, t_arg *head)
{
	long long	ret;
	int			p;

	p = head->precision;
	while (p > 0)
	{
		nbr *= 10;
		p--;
	}
	ret = (unsigned long long)(nbr - ft_floor(nbr) >= 0.5 ? ft_ceil(nbr) : ft_floor(nbr));
	return (ret);
}
