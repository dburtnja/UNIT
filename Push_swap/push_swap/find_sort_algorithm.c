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

int		if_rev_rotate(t_doub_lst *lst, int midd_nbr, int size)
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
	if ((*a)->size <= 2)
	{
		find_sort_algorithm(a, &b);
		while (b)
		{
			ps_push_stack(&b, a);
			ft_putendl("pa");
		}
	}
}

int		find_instruction_b(t_doub_lst **a, t_doub_lst **b, int midd_nbr, int rr)
{
	if ((*a)->nbr > midd_nbr)
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
	if ((*b)->size <= 2)
	{
		find_sort_algorithm(&a, b);
		while (a)
		{
			ps_push_stack(&a, b);
			ft_putendl("pb");
		}
	}
}

void	find_sort_algorithm(t_doub_lst **a, t_doub_lst **b)
{
	if ((*a)->size <= 2)
	{
		sort_small(*a, *b);
		return ;
	}
	else
	{
		dividing_lst_a(a, NULL);
		if (*b)
			dividing_lst_b(NULL, b);
	}
}

