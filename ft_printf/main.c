
#include "ft_printf.h"

#include <stdio.h>
int main(void)
{
	char i;

	char s[] = "start end";
	double d = 2.061;

	   ft_printf("start%#.Xend\n", 0);
	      printf("start%#.Xend\n", 0);
	   ft_printf("%#10X\n", 0);
	      printf("%#10X\n", 0);
	   ft_printf("%0 33..1d\n", 22222222);
	      printf("%0 33..1d\n", 22222222);

	      printf("orig: %020%\n");
	   ft_printf("ft:   %020%\n");

	   printf("orig: %+20e\n",d);
	ft_printf("ft_t: %+20e\n",d);

	ft_printf("\n\n\n\n");
	ft_printf("ft_t str: %15.5s\n", NULL);
	   printf("ft_t str: %15.5s\n", NULL);
	ft_printf("ft_t: %#15.X\n", 220);
	   printf("orig: %#15.X\n", 220);
	ft_printf("ft_t add: %-20.p\n", &i);
		 printf("orig add: %-20.p\n", &i);
	ft_putnbr(ft_printf("\b123456789%hhns\n", &i));
	   ft_putnbr(printf("\n123456789%hhns\n", &i));
	ft_printf("\nft_t n: %hhd\n", i);
       printf("orig n: %hhd\n", i);
	ft_printf("ft_t b: %hhb\n", 'c');



//	  ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	  ft_putnbr(printf("\n	 %denys  \n", 15));
	return (0);

}
