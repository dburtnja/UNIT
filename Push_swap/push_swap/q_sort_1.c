//
// Created by Denys Burtnjak on 2/23/17.
//

#include "../lib/Push_swap.h"

void	sort_small(t_doub_lst *a, t_doub_lst *b)
{
	int		a_true;
	int 	b_true;

	a_true = (a && a->next && a->nbr > a->next->nbr && a->size > 1);
	b_true = (b && b->next && b->nbr < b->next->nbr && b->size > 1);
	if (a_true && b_true)
	{
		ps_apply_to_both(&a, &b, &ps_swap_stack);
		ft_putendl("ss");
	}
	if (a_true)
	{
		ps_swap_stack(&a);
		ft_putendl("sa");
	}
	if (b_true)
	{
		ps_swap_stack(&b);
		ft_putendl("sb");
	}
}