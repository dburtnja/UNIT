
#include <stdio.h>
#include "ft_printf.h"

int		help(int nbr, ...)
{

int		ft_printf(char *str, ...)
{
	int		nbr;
	int		count;
	va_list arg_ptr;

	if (!str)
		return (-1);
	count = 0;
	nbr = count_nbr(str);
	va_start(arg_ptr, nbr);
	while (count < nbr)
	{
		printf("%d\n", va_arg(arg_ptr, int));
		count++;
	}
	va_end(arg_ptr);
}
	return (1);
}

int main(void)
{
	ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
	ft_putnbr(printf("\n   %denys  \n", 15));
	return (0);
}
