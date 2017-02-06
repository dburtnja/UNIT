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

char	*ft_strnew(int i)
{
	int		j;
	char	*ret;

	j = 0;
	ret = (char*)malloc(sizeof(char) * (i + 1));
	while (j < i + 1)
	{
		ret[j] = 0;
		j++;
	}
	return (ret);
}

char	*ret_str(char *str, int *len)
{
	char	*ret;
	int		i;

	*len = ft_strlen(str);
	i = *len;
	ret = ft_strnew(i);
	i--;
	while (i >= 0)
	{
		ret[i] = *str;
		i--;
		str++;
	}
	return (ret);
}

void	rewrite_str(char *ret, int len)
{
	int		i;
	char	c;

	i = 0;
	while (len > i)
	{
		c = ret[i];
		if (c > 9)
		{
			ret[i] = c % 10 + '0';
			ret[i + 1] += c / 10;
		}
		else
			ret[i] = c + '0';
		i++;
	}
}

char	*add_str(char *str_a, char *str_b, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(len);
	while (len > i)
	{
		ret[i] = (*str_a ? *str_a - '0' : 0) + (*str_b ? *str_b - '0' : 0);
		i++;
		if (str_a != 0)
			str_a++;
		if (str_b != 0)
			str_b++;	
	}
	rewrite_str(ret, len);
	return (ret);
}

char	*summ_res(char *str1, char *str2)
{
	int		len_a;
	int		len_b;
	char	*str_a;
	char	*str_b;
	char	*ret;

	str_a = ret_str(str1, &len_a);
	str_b = ret_str(str2, &len_b);
	ret = add_str(str_a, str_b, len_a > len_b ? len_a + 1 : len_b + 1);
	ret = ret_str(ret, &len_a);
	while (*ret == '0')
		ret++;
	return (ret);
}

char	*min_infin_add(char *str1, char *str2)
{

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
		if (argv[1][0] == '-' || argv[2][0] == '-')
			res = min_infin_add(argv[2], argv[1]);
		else
			res = summ_res(argv[1], argv[2]);
		write(1, res, ft_strlen(res));
		write(1, "\n", 1);
	}
	return (0);
}
