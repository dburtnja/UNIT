/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:22:19 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/19 19:48:21 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi_mod(char *buf, int *i)
{
	unsigned long long nb;

	nb = 0;
	while (buf[*i] != '\0' && (buf[*i] >= '0' && buf[*i] <= '9'))
	{
		nb = nb * 10 + (buf[*i] - '0');
		(*i)++;
	}
	return (nb);
}
