
#include "ft_printf.h"

int		mod_and_print(t_arg *head)
{
	char	*str;

	while (head)
	{
		ft_putstr(head->data);
		head = head->next;
	}
	return (ft_putstr(str));
}
