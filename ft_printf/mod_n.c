
#include "ft_printf.h"

void	mod_n(t_arg *head, va_list arg)
{
	head->data = (char*)va_arg(arg, void*);
	head->mod = 2;
}
