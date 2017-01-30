/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:07:43 by exam              #+#    #+#             */
/*   Updated: 2017/01/24 10:28:40 by exam             ###   ########.fr       */
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

char	*summ_res(char *str1, char *str2)
{
	char	*res;
	size_t	r_l;
	size_t	s1_l;
	size_t	s2_l;

	s1_l = ft_strlen(str1);
	s2_l = ft_strlen(str2);
	res = (char*)malloc((r_l = (sizeof(char) * s1_l > s2_l ? s1_l : s2_l) + 4));
	clear_res(res, r_l);
	while (1)
	{
		r_l--;
		s1_l--;
		s2_l--;
		res[r_l] = str1[s1_l] - '0' + str2[s2_l] - '0'; 
		if (s1_l == 0 || s2_l == 0)
			break ;	
	}
	return (res);
}

char	*colect(char *res)
{
	size_t	i;

	while (*res == 0)
		res++;
	i = ft_strlen(res) - 1;
	while (i + 1 != 0)
	{
		if (res[i] > 9)
		{
			res[i] = (res[i] % 10) + '0';
			res[i - 1] = res[i - 1] + res[i] / 10;
		}
		else
			res[i] = res[i] + '0';
		i--;
	}
	return (res);
}

int		main(int argc, char **argv)
{
	char	*res;
	char	sign;

	if (argc == 3)
	{
		if (argv[1][0] == '-' && argv[2][0] == '-')
			write(1, "-", 1);
		while (*(argv[1]) < '0' && *(argv[1]) > '9')
			(argv[1])++;
		while (*(argv[2]) < '0' && *(argv[2]) > '9')
			(argv[2])++;
		res = summ_res(argv[1], argv[2]);
		res = colect(res);
		write(1, res, ft_strlen(res));
		write(1, "\n", 1);
	}
	return (0);
}
