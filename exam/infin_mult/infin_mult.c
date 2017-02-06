/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:03:47 by exam              #+#    #+#             */
/*   Updated: 2017/01/31 12:06:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	check_min(char **argv)
{
	if (argv[1][0] ==  '-' && argv[2][0] == '-')
	{
		(argv[1])++;
		(argv[2])++;
	}
	else if (argv[1][0] == '-')
	{
		write (1, "-", 1);
		(argv[1])++;
	}
	else if (argv[2][0] == '-')
	{
		write (1, "-", 1);
		(argv[2])++;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_bzero(char *str, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		str[j] = 0;
		j++;	
	}
}

char	**creat_strs(char **argv)
{
	char	**strs;
	int		a1_l;
	int		a2_l;
	int		i;

	i = 0;
	strs = (char**)malloc(sizeof(char*) * ((a2_l = ft_strlen(argv[2])) + 1));
	a1_l = ft_strlen(argv[1]);
	while (a2_l > i)
	{
		strs[i] = (char*)malloc(sizeof(char) * (a1_l * 2 + 1));
		ft_bzero(strs[i], (a1_l * 2) + 1);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

int		main(int argc, char **argv)
{
	char	**strs;

	(void)argc;
	check_min(argv);
	strs = creat_strs(argv);
	in_mult(argv, strs, ft_strlen(argv[1]) - 1, ft_strlen(argv[2]) - 1);
	sum_strs(strs, ft_strlen(argv[1]) - 1);
	res_null(strs[0], ft_strlen(argv[1]));
	write(1, strs[1], ft_strlen(strs[1]));
	return (0);
}
