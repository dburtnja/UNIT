/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:35:50 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/08 20:36:40 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strtrim_len(char *s)
{
	int		i;

	i = 0;
	if (*s == '\0')
		return (0);
	while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
		s++;
	while (s[i] != '\0')
		i++;
	while ((s[i] == ' ' || s[i] == '\n' ||
				s[i] == '\t' || s[i] == '\0') && i > 0)
		i--;
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*buf;
	int		i;
	int		len;

	i = 0;
	if (s == NULL)
		return (NULL);
	buf = (char*)s;
	len = strtrim_len(buf);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (*buf == ' ' || *buf == '\n' || *buf == '\t')
		buf++;
	while (i < len)
	{
		str[i] = buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
