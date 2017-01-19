
#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	t_arg	*head;
	int		count;
	va_list arg_ptr;
	int		nbr;

	if (!str)
		return (-1);
	count = 0;
	head = read_str(str);
	nbr = lstlen(head);
	va_start(arg_ptr, nbr);
/*	while (count < nbr)
	{
		printf("%d\n", va_arg(arg_ptr, int));
		count++;
	}*/
	va_end(arg_ptr);
	return (mod_and_print(head, nbr));
}

#include <stdio.h>
int main(void)
{
	ft_printf("underscore\n");
//	ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	ft_putnbr(printf("\n   %denys  \n", 15));
	return (0);

}

