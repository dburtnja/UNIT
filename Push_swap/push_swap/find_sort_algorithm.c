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

void	find_sort_algorithm(t_doub_lst *a, t_doub_lst *b)
{
	int		midd_nbr;

	midd_nbr = middle_nbr(a);
	ft_putnbr(midd_nbr);
	ft_putendl("");
}