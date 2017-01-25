
#include "ft_printf.h"

void	mod_str(t_arg *head, va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char*);
	if (head->flag.min == 1)
		str = cpy_and_put_char(str, head);
	else
		str = put_char_and_cpy(str, head);
	head->data = str;
}
