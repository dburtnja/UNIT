/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:36:10 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/07 15:44:19 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char*)s1;
	buf2 = (unsigned char*)s2;
	while (*buf1 == *buf2 && *buf1 != '\0' && *buf2 != '\0')
	{
		buf1++;
		buf2++;
	}
	return (*buf1 - *buf2);
}
