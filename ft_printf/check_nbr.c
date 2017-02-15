/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 21:25:29 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/15 21:25:33 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	scan_width(char *str, int *i, va_list arg, t_arg *head)
{
	int		nbr;

	nbr = 0;
	if (str[*i] == '*')
	{
		(*i)++;
		nbr = va_arg(arg, int);
		if (nbr < 0)
		{
			nbr = -nbr;
			head->flag.min = 1;
		}
		head->width = nbr;
	}
	else if (str[*i] > '0' && str[*i] <= '9')
		head->width = ft_atoi_mod(str, i);
}

void	scan_precision(char *str, int *i, va_list arg, int *nbr)
{
	int buf;

	if (str[*i] == '*')
	{
		(*i)++;
		buf = va_arg(arg, int);
		*nbr = buf < 0 ? -1 : buf;
	}
	else if (str[*i] > '0' && str[*i] <= '9')
		*nbr = ft_atoi_mod(str, i);
}
