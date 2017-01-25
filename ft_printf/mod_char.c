
#include "ft_printf.h"

void	mod_char(t_arg *head, va_list ptr)
{
	char	*str;

	head->precision = -1;
	str = ft_strnew(1);
	str[0] = (char)va_arg(ptr, int);	
	mod_m_flag(str, head);	
}
