
#include "ft_printf.h"


int		ft_print(t_arg *head)
{
	char	*str;
	char	*new;

	str = ft_strnew(0);
	while (head)
	{
		new = ft_strjoin(str, (char*)head->data);
		ft_strdel(&(head->data));
		ft_strdel(&str);
		str = new;
		head = head->next;
	}
	return (ft_putstr(str));
}
