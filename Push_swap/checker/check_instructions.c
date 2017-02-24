
#include "../lib/Push_swap.h"

void	apply_instruction(char *inst, t_doub_lst **a, t_doub_lst **b)
{
	if (ft_strcmp(inst, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(inst, "sb") == 0)
		swap_stack(b);
	else if (ft_strcmp(inst, "ss") == 0)
		apply_to_both(a, b, &swap_stack);
	else if (ft_strcmp(inst, "pa") == 0 && *b && (*b)->size > 0)
		push_stack(b, a);
	else if (ft_strcmp(inst, "pb") == 0 && *a && (*a)->size > 0)
		push_stack(a, b);
	else if (ft_strcmp(inst, "ra") == 0)
		rotate_stack(a);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate_stack(b);
	else if (ft_strcmp(inst, "rr") == 0)
		apply_to_both(a, b, &rotate_stack);
	else if (ft_strcmp(inst, "rra") == 0)
		rev_rotate_stack(a);
	else if (ft_strcmp(inst, "rrb") == 0)
		rev_rotate_stack(b);
	else if (ft_strcmp(inst, "rrr") == 0)
		apply_to_both(a, b, &rev_rotate_stack);
	//else
	//	error();
}

int		check_if_sort(t_doub_lst *a, t_doub_lst *b)
{
	t_doub_lst	*p;

	if (b)
		return (0);
	p = a->next;
	while (p)
	{
		if (p->prev->nbr > p->nbr)
			return (0);
		p = p->next;
	}
	return (1);
}

void	print_stacks(t_doub_lst *a, t_doub_lst *b)
{
	ft_putstr("stack A:");
	while (a)
	{
		ft_putchar(' ');
		ft_putnbr(a->nbr);
		a = a->next;
	}
	ft_putchar('\n');
	ft_putstr("stack B:");
	while (b)
	{
		ft_putchar(' ');
		ft_putnbr(b->nbr);
		b = b->next;
	}
	ft_putchar('\n');
}

int		check_instructions(t_doub_lst **a, t_doub_lst **b, int flag)
{
	char	*inst;
	int		gnl_ret;

	while ((gnl_ret = get_next_line(0, &inst)) > 0)
	{
		apply_instruction(inst, a, b);
		if (flag == 1 && inst && *inst != 0)
			print_stacks(*a, *b);
		ft_strdel(&inst);
	}
	if (gnl_ret == -1)
		error();
	return (check_if_sort(*a, *b));
}