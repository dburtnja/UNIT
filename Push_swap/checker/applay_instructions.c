
#include "../lib/Push_swap.h"

void	applay_to_both(int *a, int *b, void (*f)(int*))
{
	f(a);
	f(b);
}

void	swap_stack(int *stack)
{
	int buf;

	buf = stack[0];
	stack[0] = stack[1];
	stack[1] = buf;
}

void	push_stack(int *from, int *into)
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