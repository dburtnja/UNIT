//
// Created by Denys on 20.02.2017.
//

#include "../lib/Push_swap.h"

int		check_if_sort(int *arr)
{
	int i;

	i = 2;
	while (arr[0] >= i)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	find_sort_algorithm(int *a, int *b)
{
	while (check_if_sort(a) == 0)
	{
		if (a[])
	}
}