/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/19 21:57:07 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(char *str, int *i)
{
	char	flags[5];
	char	f[5];
	int		l;
	char	*ret;

	ret = NULL;
	ft_bzero(&f[0], 5);
	flags = "+-# 0";
	while (find_c(str[*i], &flags[0], 0))
	{
		find_c(str[*i], f, 1);
		*i++;
	}
	if (ft_strlen(f) > 0)
		ret = ft_strdup(f);
	return (f);
}

int		check_nbr(char *str, int *i)
{
	int		ret;
	int		b;

	ret = 0;
	b = 1;
	while (str[*i] == '*')
	{
		b = -1;
		*i++;
	}
	if ((ret = ft_atoi_mod(str, i)) == 0 && b == -1)
		return (-1);
	return (ret * b);
}

char	*check_size(char *str, int *i)
{
	char	sizes[10];
	char	s[2];
	int		l;
	char	*ret;

	ret = NULL:
}
