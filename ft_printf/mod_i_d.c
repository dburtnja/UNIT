
#include "ft_printf.h"

char	*put_sign(int *nbr, t_arg *head)
{
	if (*nb < 0)
	{
		*nb *= -1;
		return ("-");
	}
	else if (head->flag.pl == 1)
	{
		return ("+");
	}
	else if (head->flag.space == 1)
		return (" ");
	return ("\0");
}

void	mod_int(t_arg *head, va_list arg)
{
	int		nbr;
	char	*sign;

	nbr = va_arg(arg, int);
	sign = put_sign(&nbr, head);
	head->flag.hesh = 0;
	if (head->flag.min == 0 && head->flag.nul == 1)
		
	ft_itoa_base(nbr, 10, 0, 
}

void	mod_i_d(t_arg *head, va_list arg)
{
	if (head->size == 0)
		mod_int(head, arg);	
}
