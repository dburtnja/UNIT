/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:33:18 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/02 20:35:05 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*buf;

	buf = (char*)s;
	i = 0;
	while (i < n)
	{
		if ((char)c == *buf)
			return (buf);
		buf++;
		i++;
	}
	return (NULL);
}
