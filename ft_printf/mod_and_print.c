
#include "ft_printf.h"

void	write_to_n(t_arg *head, size_t len)
{
	if (head->size == 0)
		*(head->data) = (int)len;
	else if (head->size == 1)
		*(head->data) = (signed char)len;
	else if (head->size == 2)
		*(head->data) = (short int)len;
	else if (head->size == 3)
		*(head->data) = (long)len;
	else if (head->size == 4)
		*(head->data) = (long long)len;
}

int		ft_print(t_arg *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		if (head->mod != 2)
		{
			len = len + ft_putstr(head->data);
			ft_strdel(&(head->data));
		}
		else
			write_to_n(head, len);
		head = head->next;
/*
		new = ft_strjoin(str, (char*)head->data);
		ft_strdel(&(head->data));
		ft_strdel(&str);
		str = new;
		head = head->next;*/
	}
	return (len);
}
