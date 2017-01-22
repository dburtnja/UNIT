
#include "ft_printf.h"
/*
int		read_type(t_arg *p, va_list ptr)
{
	
			read_type(
}*/

int		read_arg(t_arg *head, va_list ptr)
{
	while (head)
	{
		if (head->mod == 1)
		{
			//if (head
			head->data = va_arg(ptr, char*);
		}
		head = head->next;
	}
	return (0);
}
