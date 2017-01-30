/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:49:46 by exam              #+#    #+#             */
/*   Updated: 2017/01/24 13:55:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*mem_alloc(size_t l)
{
	char *str;
	size_t		i;

	i = 0;
	str = (char*)malloc(sizeof(char));
	while (i < l)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

void	mult_to_res(char *res, int d, size_t l_1)
{
	if (res[l_1] != 0)
		res[l_1] = res[l_1] + (d % 10);
	else
		res[l_1] = (d % 10) + '0';
	if (d / 10 > 0)
		res[l_1 - 1] = (d / 10) + '0';
}

char	*ft_str_mult(char *str1, char c, size_t l_1)
{
	int		b;
	int		i;
	char	*res;

	i = 1;
	res = mem_alloc(l_1 * 2);
	while (l_1 > 0)
	{
		b = (str1[l_1] - '0') * (c - '0');
		mult_to_res(res, b, l_1);	
		l_1--;	
	}
	return (res);
}

void	ft_mult(char **str, char *str1, char *str2, size_t l_1, size_t l_2)
{
	size_t i_2;

	i_2 = 0;
	while (l_2 > 0)
	{
		str[i_2] = ft_str_mult(str1, str2[l_2], l_1); 
		i_2++;
		l_2--;
	}
}

char	*ft_sum_to_res(char *str1, char *str2, int i, size_t l_1)
{
	int		b;
	int		l;
	size_t 	lstr;
	char	*res;

	l = 1000 - i;
	lstr = l_1 * 2;
	res = mem_alloc(1000);
	while (str1[lstr] != 0)
	{
		b = (str1[lstr] ? str1[lstr] : '0' ) + (str2[lstr] ? str2[lstr] : '0');
		mult_to_res(res, b, l);
		lstr--;
	}
	return (res);
}

char	*sum_str(char **str, size_t l_1)
{
	int		i;
	char	*s = mem_alloc(l_1 * 2);

	i = 0;
	str[0] = ft_sum_to_res(s, str[0], i, l_1);
	while (str[i + 1])
	{
		str[i + 1] = ft_sum_to_res(str[i], str[i + 1], i, l_1);
		i++;
	}
	return (str[i]);
}

int		main(int argc, char **argv)
{
	char **str;
	char *res;
	size_t	l_1;
	size_t	l_2;

	if (argc == 3)
	{
		l_1 = ft_strlen(argv[1]);
		l_2 = ft_strlen(argv[2]);
		str = (char**)malloc((sizeof(char*) * l_2) + 1);
		ft_mult(str, argv[1], argv[2], l_1, l_2);
		res = sum_str(str, l_1);
		while (*res == 0)
			res++;
		write(1, "\n", 1);
	}
	return (0);
}
