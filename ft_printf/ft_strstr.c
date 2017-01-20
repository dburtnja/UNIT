/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:14:24 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/20 22:21:08 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	main(void)
{
	char *sizes[8];

	
	sizes[0] = "hh";
	sizes[1] = "h";
	sizes[2] = "l";
	sizes[3] = "ll";
	sizes[4] = "j";
	sizes[5] = "z";
	sizes[6] = "t";
	sizes[7] = "L";

	char str[] = "hh";
	char	*p;
	char   *s = &str[0];
     p =  ft_strstr(sizes[0], s);
	 ft_putstr(p);
int i = 0;
i = 	p - sizes[0];
	  ft_putnbr(i);


}
