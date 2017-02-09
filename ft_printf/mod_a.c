
#include "ft_printf.h"

void	add_p_nbr(long double nbr, int p, char **str, t_arg *head)
{
	int		buf;
	char	c;

	c = head->type == 17 ? 'a' : 'A';
	buf = (int)nbr;
	nbr = nbr - (long double)buf;
	while (p > 0)
	{
		nbr *= 16;
		buf = (int)nbr;
		nbr = nbr - (long double)buf;
		**str = buf >= 10 ? buf - 10 + c : buf + '0';
		(*str)++;	
		p--;
	}
}

void	add_power(t_arg *head, 

char	*write_a(long double nbr, t_arg *head, int c)
{
	char	*s;
	char	*str;
	int		len[9];
	char	sign;

	head->precision = head->precision == -1 ? 13 : head->precision;
	sign = mk_sign_d(&nbr, head, &len[1]);
	len[4] = 1;
	str = all_len(&len[0], head, ft_nbrlen(c < 0 ? -c : c, 10));
	s = str;
	str = add_nul(str, sign, len[3] + len[1], head->type == 17 ? 'x' : 'X');
	nbr_to_str((long long)nbr, 10, &str, 0);
	if (len[5] == 1)
	{
		*str = '.';
		str++;
	}
	add_p_nbr(nbr, len[6], &str, head);
	*str = head->type == 17 ? 'p' : 'P';
	return (s);
}

char	*mod_a(long double nbr, t_arg *head)
{
	unsigned long long	buf;
	int					count;

	count = 0;
	buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	while (buf == 0 && nbr != 0)
	{
		count--;
		nbr *= 2;
		buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	}
	while (buf > 1)
	{
		count++;
		nbr /= 2;
		buf = (unsigned long long)(nbr < 0 ? nbr * -1 : nbr);
	}
	return (write_a(nbr, head, count));
}
