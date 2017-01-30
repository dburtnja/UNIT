/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 min_infin_add.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: dburtnja <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/01/30 17:36:41 by dburtnja		   #+#	  #+#			  */
/*	 Updated: 2017/01/30 18:15:32 by dburtnja		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "infin_add.h"

char	*colect_m(char *res, int i)
{
	while (*res == 0 && i > 0)
	{
		i--;
		res++;
	}
	if (i == 0)
		return (NULL);
	while (1)
	{
		if (res[i] < 0)
		{
			res[i - 1] = res[i - 1] - 1;
			res[i] = (10 + res[i]) + '0';
		}
		else
			res[i] = res[i] + '0';
		i--;
		if (i == 0)
		{
			if (res[-1] == -1)
			{
				write(1, "-", 1);
			}
			break ;
		}
	}
	return (res);
}

char	*min_infin_add(char *strU, char *strD)
{
	char	*res;
	int		r_l;
	int		s1_l;
	int		s2_l;
	int		i;

	s1_l = ft_strlen(strU);
	s2_l = ft_strlen(strD);
	res = (char*)malloc((r_l = (sizeof(char) * s1_l > s2_l ? s1_l : s2_l) + 4));
	i = r_l;
	clear_res(res, r_l);
	while (s1_l > -1 || s2_l > -1)
	{
		r_l--;
		s1_l--;
		s2_l--;
		res[r_l] = (s1_l > -1 ? strU[s1_l] - '0' : 0) - (s2_l > -1 ? strD[s2_l] - '0' : 0);
	}
	return (colect_m(res, i - 1));
}
