/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:13:48 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/10 14:31:49 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*p;

	p = (char*)big;
	if (*little == '\0')
		return (p);
	i = 0;
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (p[k] == little[j] && k < len)
		{
			k++;
			j++;
			if (little[j] == '\0')
				return (p + i);
		}
		i++;
	}
	return (NULL);
}
