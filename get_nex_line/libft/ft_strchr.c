/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:21:09 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/07 13:12:21 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *buf;

	buf = (char*)s;
	while (*buf != (char)c && *buf != '\0')
		buf++;
	if (*buf != (char)c)
		return (NULL);
	return (buf);
}
