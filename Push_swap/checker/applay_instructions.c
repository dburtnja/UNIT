
#include "../lib/Push_swap.h"

void	applay_to_both(t_doub_lst **a, t_doub_lst **b, void (*f)(t_doub_lst**))
{
	f(a);
	f(b);
}

void	swap_stack(t_doub_lst **stack)
{
	int buf;

	if ((*stack)->size > 1)
	{
		buf = (*stack)->nbr;
		(*stack)->nbr = (*stack)->next->nbr;
		(*stack)->next->nbr = buf;
	}
}

void	push_stack(t_doub_lst **from, t_doub_lst **into)
{
	t_doub_lst	*p;

	p = *from;
	(*from)->next->size = p->size - 1;
	add_lst_to_front(into, p);
	*from = (*from)->next;
	(*from)->prev = NULL;
}

void	rotate_stack(t_doub_lst **head)
{
	t_doub_lst	*front;

	if ((*head)->size > 1)
	{
		front = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		(*head)->size = front->size;
		front->size = 0;
		front->next = NULL;
		add_lst_to_back(head, front);
	}
}

void	rev_rotate_stack(t_doub_lst **head)
{
	t_doub_lst	*p;
	t_doub_lst	*last;

	if ((*head)->size > 1)
	{
		p = *head;
		while (p->next)
			p = p->next;
		last = p->prev;
		last->next = NULL;
		p->prev = NULL;
		(*head)->size--;
		add_lst_to_front(head, p);
	}
}