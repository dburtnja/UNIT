/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:54:40 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/10 18:07:49 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest, const void *restrict src, int c,
		size_t n)
{
	size_t			i;
	unsigned char	*buf_d;
	unsigned char	*buf_s;

	buf_d = (unsigned char*)dest;
	buf_s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*buf_d = *buf_s;
		if (*buf_d == (unsigned char)c)
			return ((void*)buf_d + 1);
		buf_s++;
		buf_d++;
		i++;
	}
	return (NULL);
}
