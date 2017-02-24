//
// Created by Denys Burtnjak on 2/23/17.
//

#include "../lib/Push_swap.h"

void	sort_small(t_doub_lst *a, t_doub_lst *b)
{
	if (a->nbr > a->next->nbr && b->size == 2 && b->nbr < b->next->nbr)
	{
		ps_apply_to_both(&a, &b, &ps_swap_stack);
		ft_putendl("ss");
	}
	if (a->nbr > a->next->nbr)
	{
		ps_swap_stack(&a);
		ft_putendl("sa");
	}
	if (b->size == 2 && b->nbr < b->next->nbr)
	{
		ps_swap_stack(&b);
		ft_putendl("sb");
	}
}

