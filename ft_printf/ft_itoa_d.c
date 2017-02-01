
#include "ft_printf.h"

long long	add_precision(long double nbr, t_arg *head)
{
	int		p;

	p = head->precision;
	while (p > 0)
	{
		nbr = nbr * 10;
		p--;
	}
	return ((long long)nbr);
}

char		*make_str(long long r_nbr, long long f_nbr, t_arg *head)
{
	char	sign;
	int		len;

	sign = mk_sign(&r_nbr, head, &len);
	len = len + ft_nbrlen(r_nbr, 10);
	if (head->precision > 0)
		len = len + 1 + head->precision;
	else if (head->flag.hesh == 1)
		len++;
	if (head->flag.nul == 1 && head->width > len)
		len = head->width;	
	
}

char		*ft_itoa_d(long double value, t_arg *head)
{
	char		*str;
	long long	r_nbr;
	long long	f_nbr;

	r_nbr = (long long)value;
	if (head->precision > 0)
		f_nbr = add_precision(vlaue - (long double)r_nbr, head);
	str = make_str(r_nbr, f_nbr, head);
	

}
