
#include "ft_printf.h"

int		read_arg(t_arg *head, va_list ptr)
{
	while (head)
	{
		if (head->mod == 1)
			head->data = va_arg(ptr, char*);
		head = head->next;
	}
	return (0);
}
