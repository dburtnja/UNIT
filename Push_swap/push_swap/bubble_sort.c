//
// Created by Denys Burtnjak on 2/23/17.
//

#include "../lib/Push_swap.h"

t_doub_lst	*bubble_sort(t_doub_lst *lst)
{
	int 		end;
	int 		buf;
	t_doub_lst	*p;

	end = 0;
	while (!end)
	{
		p = lst;
		end = 1;
		while (p->next)
		{
			if (p->nbr > p->next->nbr)
			{
				end = 0;
				buf = p->nbr;
				p->nbr = p->next->nbr;
				p->next->nbr = buf;
			}
			p = p->next;
		}
	}
	return (lst);
}