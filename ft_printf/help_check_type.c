/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/15 21:21:05 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char *str, int *i, t_flag *flag)
{
	if (h_check_flags(str[*i], '+', &(flag->pl)))
		(*i)++;
	else if (h_check_flags(str[*i], '-', &(flag->min)))
		(*i)++;
	else if (h_check_flags(str[*i], '#', &(flag->hesh)))
		(*i)++;
	else if (h_check_flags(str[*i], ' ', &(flag->space)))
		(*i)++;
	else if (h_check_flags(str[*i], '0', &(flag->nul)))
		(*i)++;
}

void	create_sizes(char *sizes[])
{
	sizes[0] = "hh";
	sizes[1] = "h";
	sizes[2] = "l";
	sizes[3] = "ll";
	sizes[4] = "j";
	sizes[5] = "z";
	sizes[6] = "t";
	sizes[7] = "L";
}

int		h_check_size(int *i, char *str, int k)
{
	int		z;
	char	*sizes[8];
	int		j;

	z = 0;
	j = *i;
	create_sizes(sizes);
	while (j - *i < 2 && sizes[k][z] != 0)
	{
		if (sizes[k][z] == str[j])
		{
			j++;
			z++;
		}
		else
			break ;
	}
	if (j - *i == 2 || (sizes[k][z] == 0 && !(str[j] == 'l' && k == 2)))
	{
		*i = j;
		return (k + 1);
	}
	return (0);
}

int		check_size(char *str, int *i)
{
	int		k;
	int		j;

	k = 0;
	while (k < 8)
	{
		if ((j = h_check_size(i, str, k)) != 0)
			return (j);
		k++;
	}
	return (0);
}
