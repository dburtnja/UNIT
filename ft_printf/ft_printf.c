#include "../libft/libft.h"
#include <stdarg.h>

/*int		ft_printf(const char *restrict format, ...)
{
	char str;
	int num = 2;

	va_list argptr;
	va_start (argptr, num);
	
	ft_putstr(va_arg(argptr, char));
	num--;
	ft_putstr(va_arg(argptr, char));
	return (0);
}

int main(void)
{
	ft_printf("aaa %s \n %s\n", "first", "second");
	return (0);

}
*/
#include <stdio.h>		/* printf */
#include <stdarg.h>		/* va_list, va_start, va_arg, va_end */

void PrintFloats (char str, ...)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			j++;
		i++;
	}
	char	*val;
	printf ("Printing floats:");
	va_list vl;
	va_start(vl,n);
	for (i=0;i<n;i++)
	{
		val=va_arg(vl, char*);
		printf ("%s", val);
	}
	va_end(vl);
	printf ("\n");
}

int main ()
{
	  PrintFloats ("print first: %s\n print second: %s\n print third %s\n", "first ", "second ", "third ");
		return 0;
}
