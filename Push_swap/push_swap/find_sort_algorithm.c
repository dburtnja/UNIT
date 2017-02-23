//
// Created by Denys on 20.02.2017.
//

#include "../lib/Push_swap.h"

int 	middle_nbr(t_doub_lst *head)
{
	int 		i;
	t_doub_lst	*sort_lst;

	sort_lst = bubble_sort(lst_dup(head));
	i = head->size / 2;
	while (i > 0)
	{
		sort_lst = sort_lst->next;
		i--;
	}
	return (sort_lst->nbr);
}

int		find_lower_half(t_doub_lst *lst, int midd_nbr, int size)
{
	int 	left;
	int 	i;

	i = 0;
	left = 0;
	while (i < size)
	{
		if (midd_nbr > lst->nbr)
			left++;
		i++;
	}
	if (size - left > left)
		return (1);
	return (0);
}

void	write_instractions()
{
	int 	midd_nbr;
	int 	size;

	size = a->size / 2;
	midd_nbr = middle_nbr(a);
	while (size > 0)
	{
		if ()
	}
}

void	find_sort_algorithm(t_doub_lst *a, t_doub_lst *b)
{
	if (a->size <= 3)
	{
		sort_three(&a);
		return ;
	}
	else
	{

	}
}

