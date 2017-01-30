/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:07:43 by exam              #+#    #+#             */
/*   Updated: 2017/01/30 20:49:15 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_add.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	clear_res(char *res, size_t i)
{
	while (i > 0)
	{
		res[i] = 0;
		i--;
	}
}

char	*colect(char *res, int i)
{
	while (1)
	{
		if (res[i] > 9)
		{
			res[i - 1] = res[i - 1] + res[i] / 10;
			res[i] = (res[i] % 10) + '0';
		}
		else
			res[i] = res[i] + '0';
		i--;
		if (i == 0)
			break ;
	}
	res[i] = res[i] ? res[i] + '0' : 0;
	return (res);
}

char	*summ_res(char *str1, char *str2)
{
	char	*res;
	int		r_l;
	int		res_l;
	int		s1_l;
	int		s2_l;

	s1_l = ft_strlen(str1);
	s2_l = ft_strlen(str2);
	res = (char*)malloc((r_l = (sizeof(char) * s1_l > s2_l ? s1_l : s2_l) + 4));
	res_l = r_l;
	clear_res(res, r_l);
	while (s1_l > -1 || s2_l > -1)
	{
		r_l--;
		s1_l--;
		s2_l--;
		res[r_l] = (s1_l > -1 ? str1[s1_l] - '0' : 0) + (s2_l > -1 ? str2[s2_l] - '0' : 0); 
	}
	return (colect(res, res_l - 1));
}

int		main(int argc, char **argv)
{
	char	*res;
	char	sign;

	if (argc == 3)
	{
		if (argv[1][0] == '-' && argv[2][0] == '-')
		{
			write(1, "-", 1);
			(argv[1])++;
			(argv[2])++;
		}
		if (argv[1][0] == '-')
		{
			(argv[1])++;
			res = min_infin_add(argv[2], argv[1]);
		}
		else if (argv[2][0] == '-')
		{
			(argv[2])++;
			res = min_infin_add(argv[1], argv[2]);
		}
		else
		{
			res = summ_res(argv[1], argv[2]);
		}
		if (res == NULL)
		{
			write(1, "0\n", 2);
			return (0);
		}
		while (*res == 0 || *res == '0')
				res++;
		write(1, res, ft_strlen(res));
		write(1, "\n", 1);
	}
	return (0);
}
