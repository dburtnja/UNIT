/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:51:04 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 15:27:54 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(unsigned long long i, unsigned long long base)
{
	int c;

	c = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / base;
		c++;
	}
	return (c);
}
