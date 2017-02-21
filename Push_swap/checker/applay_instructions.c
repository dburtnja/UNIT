
#include "../lib/Push_swap.h"

void	applay_to_both(t_doub_lst *a, t_doub_lst *b, void (*f)(t_doub_lst*))
{
	f(a);
	f(b);
}

void	swap_stack(t_doub_lst *stack)
{
	int buf;

	if (stack->size > 1)
	{
		buf = stack->nbr;
		stack->nbr = stack->next->nbr;
		stack->next->nbr = buf;
	}
}

void	push_stack(t_doub_lst *from, t_doub_lst *into)
{


	ft_memmove((void*)&into[2], (void*)&into[1], (sizeof(int) * into[0]));
	into[1] = from[1];
	into[0]++;
	from[0]--;
	ft_memmove((void*)&from[1], (void*)&from[2], (sizeof(int) * from[0]));
	from[from[0] + 1] = 0;
}

void	rotate_stack(int *arr)
{
	int		buf;

	if (arr[0] > 1)
	{
		buf = arr[1];
		ft_memmove((void *) &arr[1], (void *) &arr[2],
				   (sizeof(int) * (arr[0] - 1)));
		arr[arr[0]] = buf;
	}
}

void	rev_rotate_stack(int *arr)
{
	int 	buf;

	if (arr[0] > 1)
	{
		buf = arr[arr[0]];
		ft_memmove((void *) &arr[2], (void *) &arr[1],
				   (sizeof(int) * (arr[0] - 1)));
		arr[1] = buf;
	}
}