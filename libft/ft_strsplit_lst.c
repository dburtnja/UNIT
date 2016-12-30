/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:14:51 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/11 18:15:36 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*write_word(char *s, char *buf, char c)
{
	while (*s != c && *s != '\0')
	{
		*buf = *s;
		s++;
		buf++;
	}
	*buf = '\0';
	return (s);
}

static t_list	*make_list(char **str, char c)
{
	size_t	len;
	char	*buf;
	char	*s;

	s = *str;
	len = ft_lentoc(s, c);
	buf = ft_strnew(len);
	s = write_word(s, buf, c);
	*str = s;
	return (ft_lstnew(buf, len + 1));
}

t_list			*ft_strsplit_lst(char const *s, char c)
{
	t_list	*head;
	t_list	*p;
	char	*str;

	str = (char*)s;
	while (*str == c)
		str++;
	head = make_list(&str, c);
	p = head;
	while (*str != '\0')
	{
		if (*str != c)
		{
			p->next = make_list(&str, c);
			p = p->next;
		}
		if (str != '\0')
			str++;
	}
	return (head);
}
