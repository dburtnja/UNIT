/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 10:03:47 by exam              #+#    #+#             */
/*   Updated: 2016/12/27 10:21:02 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int main(int a, char **b)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	res = NULL;
	if (a == 2)
	{
		res = (char*)malloc(sizeof(char) * 4096);
		i = 0;
		while(res[i])
		{
			res[i] = '\0';
			i++;
		}
		i = 0;
		j = 0;
		k = 0;
		while(b[1][i])
		{
			if (b[1][i] == '>')
				j++;
			else if (b[1][i] == '<')
					j--;
			else if (b[1][i] == '+')
					res[j]++;
			else if (b[1][i] == '-')
					res[j]--;
			else if (b[1][i] == '.')
				write(1, &res[j], 1);
			else if (b[1][i] == '[')
			{
				if(!res[j])
				{
					k = 1;
					while (k)
					{
						i++;
						if (b[1][i] == '[')
							k++;
						else if (b[1][i] == ']')
							k--;
					}
				}
			}
			else if (b[1][i] == ']')
			{
				if(res[j])
				{
					k = 1;
					while (k)
					{
						i--;
						if (b[1][i] == ']')
							k++;
						else if (b[1][i] == '[')
							k--;
					}
				}
			}
			i++;
		}
	}
	else
		write(1, "\n", 1);
	free(res);
	return (0);
}
