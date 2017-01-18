
#include "ft_printf.h"

int		mod_and_print(t_arg *head, int nbr)
{
	char	*str;

	if (nbr == 0)
		str = (char*)head->data;
	else
	{
		ft_putstr("else");
	}
	return (ft_putstr(str));
}
