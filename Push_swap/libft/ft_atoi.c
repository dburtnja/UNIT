/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:22:19 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/10 18:06:43 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_h(char *buf, int s)
{
	unsigned long long nb;

	nb = 0;
	while (*buf != '\0' && (*buf >= '0' && *buf <= '9'))
	{
		nb = nb * 10 + (*buf - '0');
		buf++;
		if (nb > 9223372036854775807 && s == -1)
			return (0);
		if (nb > 9223372036854775807)
			return (-1);
	}
	nb = nb * s;
	return (nb);
}

int			ft_atoi(const char *nptr)
{
	int		s;
	char	*buf;

	buf = (char*)nptr;
	s = 1;
	while (*buf == ' ' || *buf == '\t' || *buf == '\v' || *buf == '\r' ||
			*buf == '\f' || *buf == '\n')
	{
		buf++;
		if (*buf == '\0')
			return (0);
	}
	if (*buf == '-')
	{
		s = -1;
		buf++;
	}
	else if (*buf == '+')
		buf++;
	return (ft_h(buf, s));
}
