
#include "ft_printf/ft_printf.h"

#include <stdio.h>
#include <limits.h>
int main(void)
{
	char i;
	char s[] = "start end";
	double d = 2.061;
	char	non[127];
	int		j = 60;
	
/*	while (j <= 257)
	{
		ft_printf("%10d %0.8b\n", j, j);
		j++;
	}*/

		ft_printf("{%-15}", L'Ë©≤');
		ft_printf("%10d %.16b\n", 8804, 8804);
		ft_printf("%10d %.16b\n", 1023, 1023);



/*

	ft_printf("\n\n\n\n");
	ft_printf("%r\n", &non[0]);
	   ft_printf("start%#.uen%.ud\n", 0, 0);
	      printf("start%#.uen%.ud\n", 0, 0);

	   ft_printf("start%hUend\n", 4294967296);
	      printf("start%hUend\n", 4294967296);
	   ft_printf("%#10.p\n", 0);
	      printf("%#10.p\n", 0);
	   ft_printf("%0 33..1d\n", 22222222);
	      printf("%0 33..1d\n", 22222222);

	      printf("orig: %020%\n");
	   ft_printf("ft:   %020%\n");

	   printf("orig: %+20e\n",d);
	ft_printf("ft_t: %+20e\n",d);

	ft_printf("ft_t str: %15.5Send\n", "з±≥");
	   printf("org  str: %15.5Send\n", "з±≥");
	ft_printf("ft_t: %#.xe\n", 0);
	   printf("orig: %#.xe\n", 0);
	ft_printf("ft_t add: %-20.p\n", &i);
		 printf("orig add: %-20.p\n", &i);
	ft_putnbr(ft_printf("\b123456789%hhns\n", &i));
	   ft_putnbr(printf("\n123456789%hhns\n", &i));
	ft_printf("\nft_t n: %hhd\n", i);
       printf("orig n: %hhd\n", i);
	ft_printf("ft_t b: %hhb\n", 'c');

*/

//	  ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	  ft_putnbr(printf("\n	 %denys  \n", 15));
	return (0);

}