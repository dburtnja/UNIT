//
// Created by Denys on 20.02.2017.
//

#include "../lib/Push_swap.h"

int		find_instruction_a(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int rr)
{
	if ((*a)->nbr < midd_nbr)
	{
		ps_push_stack(a, b);
		ft_putendl("pb");
		return (1);
	}
	if (rr)
	{
		ps_rev_rotate_stack(a);
		ft_putendl("rra");
	}
	else
	{
		ps_rotate_stack(a);
		ft_putendl("ra");
	}
	return (0);
}

void	dividing_lst_a(t_doub_lst **a, t_doub_lst *b)
{
	int 	midd_nbr;
	int 	size;
	int 	rr;

	size = (*a)->size / 2;
	midd_nbr = middle_nbr(*a);
	rr = if_rev_rotate(*a, midd_nbr, size);
	while (size > 0)
	{
		if (find_instruction_a(a, &b, midd_nbr, rr) == 1)
			size--;
	}
	find_sort_algorithm(a, &b);
	while (b)
	{
		ps_push_stack(&b, a);
		ft_putendl("pa");
	}
}

int		find_instruction_b(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int rr)
{
	if ((*b)->nbr >= midd_nbr)
	{
		ps_push_stack(b, a);
		ft_putendl("pa");
		return (1);
	}
	if (rr)
	{
		ps_rev_rotate_stack(b);
		ft_putendl("rrb");
	}
	else
	{
		ps_rotate_stack(b);
		ft_putendl("rb");
	}
	return (0);
}

void	dividing_lst_b(t_doub_lst *a, t_doub_lst **b)
{
	int 	midd_nbr;
	int 	size;
	int 	rr;

	size = (*b)->size / 2;
	midd_nbr = middle_nbr(*b);
	rr = if_rev_rotate(*b, midd_nbr, size);
	while (size > 0)
	{
		if (find_instruction_b(&a, b, midd_nbr, !rr) == 1)
			size--;
	}
	find_sort_algorithm(&a, b);
	while (a)
	{
		ps_push_stack(&a, b);
		ft_putendl("pb");
	}
}

void	find_sort_algorithm(t_doub_lst **a, t_doub_lst **b)
{
	sort_small(*a, *b);
	if (*a && (*a)->size > 2 && check_if_sort_a(*a) == 0)
		dividing_lst_a(a, NULL);
	if (*b && (*b)->size > 2 && check_if_sort_b(*b) == 0)
		dividing_lst_b(NULL, b);
}

