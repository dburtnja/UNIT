
#include "ft_printf.h"

int		lstlen(t_arg *head)
{
	int	i;
	
	i = 0;
	while (head)
	{
		if (head->mod == 1)
			i++;
		head = head->next;
	}
	return (i);
}

int		colect_lst(t_arg **head, t_arg *lst)
{
	t_arg	*p;

	if (lst == NULL)
		return (0);
	if (*head == NULL)
		*head = lst;
	else
	{
		p = *head;
		while (p->next)
			p = p->next;
		p->next = lst;
	}
	return (1);
}

t_arg	*new_lst(void *data, int mod)
{
	t_arg	*new;

	new = (t_arg*)malloc(sizeof(t_arg));
	if (!new)
		exit (1);
	new->next = NULL;
	new->mod = mod;
	new->data = data;
	new->flag.pl = 0;
	new->flag.min = 0;
	new->flag.hesh = 0;
	new->flag.space = 0;
	new->flag.nul = 0;
	new->width = 0;
	new->w_star = 0;
	new->precision = 0;
	new->p_star = 0;
	new->size = 0;
	new->type = 0;
	return (new);
}
