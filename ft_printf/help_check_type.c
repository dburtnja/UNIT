/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/20 21:44:00 by dburtnja         ###   ########.fr       */
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

int		check_nbr(char *str, int *i, int f, int *star)
{
	if (str[*i] != '.' && f == 1)
		return (0);
	if ((str[*i + 1] != '*' || (str[*i + 1] < '0' && str[*i + 1] > '9'))
			&& f == 1)
		return (0);
	if (str[i] == '*')
	{
		while (str[*i] == '*')
			*i++;
		*star = 1;
		return (0);
	}
	else
		return (ft_atoi_mod(str, i));
}

int		find_type(char *str, int *type)
{
	char	types[18];
	int		n;

	n = 0;
	types = "diuoxXfFeEgGaAcspn";
	while (find_c(str[n], &types[0], 0) == 0)
		n++;
	return (n);
}

char	**create_sizes(void)
{
	char	sizes[8][2];

	sizes[0] = "hh";
	sizes[1] = "h";
	sizes[2] = "l";
	sizes[3] = "ll";
	sizes[4] = "j";
	sizes[5] = "z";
	sizes[6] = "t";
	sizes[7] = "L";
	return (sizes);
}

int		check_size(char *str, int *i)
{
	char	**sizes;
	int		l;

	sizes = create_sizes(); 
	while (find_c(str[*i], sizes[l], )
	{
		
	}
	return (0);
}
