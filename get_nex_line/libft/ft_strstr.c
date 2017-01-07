/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:14:24 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/10 12:58:02 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	char	*buf;

	buf = (char*)big;
	if (little[0] == '\0')
		return (buf);
	while (*buf != '\0')
	{
		i = 0;
		while (buf[i] == little[i] && little[i] != '\0')
			i++;
		if (little[i] == '\0')
			break ;
		buf++;
	}
	if (*buf == '\0')
		return (NULL);
	return (buf);
}
