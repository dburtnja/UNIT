/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:20:24 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/10 16:34:03 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;
	size_t	i;

	i = ft_strlen(s);
	buf = (char*)s;
	buf = buf + i;
	while (i > 0)
	{
		if (*buf == (char)c)
			return (buf);
		i--;
		buf--;
	}
	if (*buf == (char)c)
	{
		return (buf);
	}
	return (NULL);
}
