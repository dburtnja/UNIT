
#include "ft_printf.h"

void	mod_void(t_arg *head, va_list ptr)
{
	char				*str;
	unsigned long long	ad;

	head->flag.hesh = 1;
	head->flag.pl = 0;
	head->flag.space = 0;
	if (head->flag.min == 1)
		head->flag.nul = 0;
	ad = (unsigned long long)va_arg(ptr, void*);
	str = ft_itoa_u(ad, 16, head, 0);
	mod_m_flag(str, head);
	ft_strdel(&str);
}
