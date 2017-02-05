
#include "ft_printf.h"

void	mod_str(t_arg *head, va_list ptr)
{
	char	*str;

	str = va_arg(ptr, char*);
	head->flag.hesh = 0;
	if (str == NULL)
		mod_m_flag("(null)", head);
	else
		mod_m_flag(str, head);
}
