/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_check_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:50:26 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 21:11:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		h_check_flags(char	check, char c, int	*flag)
{
	if (check == c)
	{
		*flag = 1;
		return (1);
	}
	return (0);
}

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

void	check_nbr(char *str, int *i, va_list arg, int *nbr)
{
	if (str[*i] == '*')
	{
		(*i)++;
		*nbr = va_arg(arg, int);
	}
	else if (str[*i] > '0' && str[*i] <= '9')
		*nbr = ft_atoi_mod(str, i);
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

int		check_size(char *str, int *i)
{
	char	*sizes[8];
	int		k;
	int		j;
	int		z;

	create_sizes(sizes);
	k = 0;
	while (k < 8)
	{
		j = *i;
		z = 0;
		while (j < 2 && sizes[k][j] != 0)
		{
			if (sizes[k][z] == str[j])
			{
				j++;
				z++;
			}
			else
				break ;
		}
		if (j == 2 || (sizes[k][j] == 0 && str[j] != 'l'))
		{
			*i = j;
			return (k + 1);
		}
		k++;
	}
	return (0);
}
