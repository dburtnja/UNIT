
#include "ft_printf.h"

#include <stdio.h>
int main(void)
{
	char i;

	char s[] = "start end";

	   printf("%ld\n", sizeof(size_t));
	double d = 0.00001;


	   printf("orig: %+20g\n",d);
	ft_printf("ft_t: %+20f\n",d);

	ft_printf("\n\n\n\n");
	ft_printf("ft_t str: %15.5s\n", "admiral");
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
