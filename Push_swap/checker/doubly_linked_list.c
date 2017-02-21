//
// Created by Denys on 21.02.2017.
//

#include "../lib/Push_swap.h"

void		*add_lst_to_front(t_doub_lst **head, t_doub_lst *new)
{
	int 	buf;

	buf = 1;
	if (*head)
	{
		buf = (*head)->size + 1;
		(*head)->size = 0;
		(*head)->prev = new;
		new->next = *head;
	}
	*head = new;
	new->size = buf;
}

void		*add_lst_to_back(t_doub_lst **head, t_doub_lst *new)
{
	t_doub_lst	*p;
	int 		len;

	len = 1;
	p = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (p->next)
		{
			len++;
			p = p->next;
		}
		p = new;
		new->prev = p;
	}
	(*head)->size = len;
}

t_doub_lst	*new_lst(int nbr)
{
	t_doub_lst	*head;

	head = (t_doub_lst*)malloc(sizeof(t_doub_lst));
	if (!head)
		error();
	head->nbr = nbr;
	head->size = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}