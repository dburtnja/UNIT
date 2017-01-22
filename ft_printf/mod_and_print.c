
#include "ft_printf.h"
#include <stdio.h>

int		mod_and_print(t_arg *head)
{
	char	*str;
	char	*new;

	str = ft_strnew(0);
	while (head)
	{
		printf("\npl: %d,\tmin: %d,\thesh: %d,\tspace: %d,\t nul: %d\n", 
head->flag.pl, head->flag.min, head->flag.hesh, head->flag.space, 
head->flag.nul);
		new = ft_strjoin(str, (char*)head->data);
		ft_memdel(&(head->data));
		ft_strdel(&str);
		str = new;
		head = head->next;
	}
	return (ft_putstr(str));
}
