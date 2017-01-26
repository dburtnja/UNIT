
#include "ft_printf.h"

void	mod_str(t_arg *head, va_list ptr)
{
	head->flag.hesh = 0;
	mod_m_flag(va_arg(ptr, char*), head);
}
