
#include "ft_printf.h"
char	mk_sign(long long *value, t_arg *head, int *len)
{
	*len = 0;
	if (value < 0)
	{
		(*len)++;
		(*value) *= -1;
		return ('-');
	}
	else if (head->flag.pl == 1)
	{
		(*len)++;
		return ('+');
	}
	else if (head->flag.space == 1)
	{
		(*len)++;
		return (' ');
	}
	else
		return (0);
}

char	*ft_itoa_p(long long value, t_arg *head)
{
	int		len;
	char	sign;
	int		nbrl;
	char	*s;
	char	*str;

	sign = mk_sign(&value, head, &len);
	nbrl = ft_nbrlen(value);
	if (head->precision > nbrl)
		str = ft_strnew(len + head->precision);
	s = str;
	while (	
}
