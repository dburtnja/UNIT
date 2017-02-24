//
// Created by Denys on 21.02.2017.
//

#include "../lib/Push_swap.h"

t_doub_lst	*lst_dup(t_doub_lst *head)
{
	t_doub_lst	*p;
	t_doub_lst	*ret;

	ret = NULL;
	while (head)
	{
		p = new_lst(head->nbr);
		p->size = head->size;
		add_lst_to_back(&ret, p);
		head = head->next;
	}
	return (ret);
}

void		free_lst(t_doub_lst **head)
{
	t_doub_lst	*p;

	p = *head;
	while (p->next)
	{
		p = p->next;
		free(p->prev);
	}
	free(p->prev);
	*head = NULL;
}

void		add_lst_to_front(t_doub_lst **head, t_doub_lst *new)
{
	int 	buf;

	buf = 1;
	if (*head)
	{
		buf = (*head)->size + 1;
		(*head)->size = 0;
		(*head)->prev = new;
	}
	new->next = *head;
	*head = new;
	new->size = buf;
	new->prev = NULL;
}

void		add_lst_to_back(t_doub_lst **head, t_doub_lst *new)
{
	t_doub_lst	*p;

	p = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->prev = p;
	}
}

t_doub_lst	*new_lst(int nbr)
{
	t_doub_lst	*head;

	if ((head = (t_doub_lst*)malloc(sizeof(t_doub_lst))) == NULL)
		error();
	head->nbr = nbr;
	head->size = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}