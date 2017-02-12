/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_wint_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 22:06:50 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/12 18:53:31 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*proc_wint8(int c)
{
	unsigned char	*s;

	s = (unsigned char*)ft_strnew(2);
	s[0] = (c >> 6) + 192;
	s[1] = c << 2;
	s[1] = (s[1] >> 2) + 128;
	return ((char*)s);
}

char	*proc_wint16(int c)
{
	unsigned char	*s;

	s = (unsigned char*)ft_strnew(3);
	s[0] = (c >> 6) + 192;
	s[0] = (c >> 12) + 224;
	s[1] = c >> 4;
	s[1] = (s[1] >> 2) + 128;
	s[2] = c << 2;
	s[2] = (s[2] >> 2) + 128;
	return ((char*)s);
}
