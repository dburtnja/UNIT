/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:54:04 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/06 18:56:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buf;
	int		i;

	i = ft_strlen(s);
	buf = (char*)malloc(sizeof(char) * (i + 1));
	if (buf == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
