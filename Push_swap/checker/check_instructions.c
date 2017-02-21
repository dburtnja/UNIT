
#include "../lib/Push_swap.h"

void	applay_instruction(char *inst, t_doub_lst *a, t_doub_lst *b)
{
	if (ft_strcmp(inst, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(inst, "sb") == 0)
		swap_stack(&b[1]);
	else if (ft_strcmp(inst, "ss") == 0)
		apply_to_both(a, b, &swap_stack);
	else if (ft_strcmp(inst, "pa") == 0 && b && b->size > 0)
		push_stack(b, a);
	else if (ft_strcmp(inst, "pb") == 0 && a && a->size > 0)
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

int		check_if_sort(int *a, int *b)
{
	int i;

	if (b[0] != 0)
		return (0);
	i = 2;
	while (a[0] >= i)
	{
		if (a[i] < a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int		check_instructions(t_doub_lst *a, t_doub_lst *b)
{
	char	*inst;
	int		gnl_ret;

	while ((gnl_ret = get_next_line(0, &inst)) > 0)
	{
		applay_instruction(inst, a, b);
		ft_strdel(&inst);
	}
	if (gnl_ret == -1)
		error();
	return (check_if_sort(a, b));
}