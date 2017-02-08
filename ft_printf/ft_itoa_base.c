/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:33:06 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 15:56:40 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nbr_to_str(unsigned long long value, unsigned long long base,
		char **str, int up)
{
	char	c;

	if (value >= base)
	{
		nbr_to_str(value / base, base, str, up);
		nbr_to_str(value % base, base, str, up);
	}
	else
	{
		if (value > 9)
			c = value + (up == 0 ? 'a' : 'A') - 10;
		else
			c = value + '0';
		**str = c;
		(*str)++;
	}
	**str = '\0';
}

char	*ft_itoa_base(unsigned long long value, unsigned long long base,
		int up, int nul)
{
	char	*str;
	char	*s;
	int		nbrl;

	nbrl = ft_nbrlen(value, base);
	str = ft_strnew(nbrl + nul);
	s = str;
	if (base < 2 || base > 16)
		return (s);
	while (nul > 0)
	{
		*str = '0';
		str++;
		nul--;
	}
	nbr_to_str(value, base, &str, up);
	return (s);
}
