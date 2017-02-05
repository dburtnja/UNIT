
#include "ft_printf.h"

void	mod_char(t_arg *head, va_list ptr, char c)
{
	char	*str;

	head->precision = -1;
	if ((str = ft_strnew(1)) == NULL)
		exit (1);;
	if (c == 0)
		str[0] = (char)va_arg(ptr, int);	
	else
		str[0] = c;
	mod_m_flag(str, head);	
	ft_strdel(&str);
}
