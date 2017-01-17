
#include <stdio.h>
#include "ft_printf.h"

char	*count_nbr(char *str, int *len)
{
	*len = 0;
	while (str[*len] != '\0')
	{
		if (str[*len] == '%' && check_type(&str[*len]) > 0)
		(*len)++;
	}
}

int		ft_printf(char *str, ...)
{
	int		nbr;
	int		count;
	char	**strings;
	va_list arg_ptr;

	if (!str)
		return (-1);
	count = 0;
	count_nbr(str, &nbr);
	va_start(arg_ptr, nbr);
	while (count < nbr)
	{
		printf("%d\n", va_arg(arg_ptr, int));
		count++;
	}
	va_end(arg_ptr);
	return (1);
}

int main(void)
{
	char *ch = "sdfg  hj\n";

//	ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	ft_putnbr(printf("\n   %denys  \n", 15));
	printf("%++fs", ch);
	return (0);
}
