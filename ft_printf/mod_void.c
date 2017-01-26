
#include "ft_printf.h"

void	mod_void(t_arg *head, va_list ptr)
{
	char				*str;
	unsigned long long	ad;
	int					nul;

	nul = 0;
	head->precision = -1;
	head->flag.hesh = 1;
	if (head->flag.min == 0 && head->flag.nul == 1)
		nul = head->width - 14;
	ad = (unsigned long long)va_arg(ptr, void*);	
	str = ft_itoa_base(ad, 16, 0, nul);
	mod_m_flag(str, head);
	ft_strdel(&str);
}
