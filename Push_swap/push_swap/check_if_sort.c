//
// Created by Denys on 24.02.2017.
//

#include "../lib/Push_swap.h"

int		check_if_sort_a(t_doub_lst *a)
{
	a = a->next;
	while (a)
	{
		if (a->prev->nbr > a->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int		check_if_sort_b(t_doub_lst *b)
{
	b = b->next;
	while (b)
	{
		if (b->prev->nbr < b->nbr)
			return (0);
		b = b->next;
	}
	return (1);
}
