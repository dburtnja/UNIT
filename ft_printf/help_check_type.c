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
	if (h_check_flags(*str, '+', &(flag->pl)))
		(*i)++;
	else if (h_check_flags(*str, '-', &(flag->min)))
		(*i)++;
	else if (h_check_flags(*str, '#', &(flag->hesh)))
		(*i)++;
	else if (h_check_flags(*str, ' ', &(flag->space)))
		(*i)++;
	else if (h_check_flags(*str, '0', &(flag->nul)))
		(*i)++;
}

int		check_nbr(char *str, int *i, int f, int *star)
{
	if (str[*i] != '.' && f == 1)
		return (0);
	if ((str[*i + 1] != '*' || (str[*i + 1] < '0' && str[*i + 1] > '9'))
			&& f == 1)
		return (0);
	if (str[*i] == '*')
	{
		(*i)++;
		(*star)++;
		return (0);
	}
	else
		return (ft_atoi_mod(str, i));
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

	create_sizes(sizes);
	k = 0;
	while (k < 8)
	{
		j = 0;
		while (j < 2 && sizes[k][j] != 0)
		{
			if (sizes[k][j] == str[j])
				j++;
			else
				break ;
		}
		if (j == 2 || (sizes[k][j] == 0 && str[j] != 'l'))
		{
		*i += j;
		return (k + 1);
		}
		k++;
	}
	return (0);
}
