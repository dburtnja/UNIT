/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_infin_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:44:37 by exam              #+#    #+#             */
/*   Updated: 2017/01/31 12:03:33 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

char	*res_null(char *str, int len)
{
	while ((*str == 0 || *str == '0') && len - 1 > 0)
	{
		str++;
		len--;
	}
	return (str);
}

void	in_mult(char **argv, char **strs, int l1, int l2)
{
	int		i;
	int		k;

	k = 0;
	while (l2 > -1)
	{
		i = l1;
		while (i > -1)
		{
			strs[k][i - k] = (argv[1][i] - '0') * (argv[2][l2] - '0');
			i--;
		}
		move_int(strs[k], l1);
		k++;
		l2--;
	}
}

void	move_int(char *str, int l1)
{
	while (l1 > -1)
	{
		if (str[l1] > 9)
		{
			str[l1 - 1] = str[l1 - 1] + (str[l1] / 10);
			str[l1] = str[l1] % 10;
		}
		l1--;
	}
}
