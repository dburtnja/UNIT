#include "ft_printf/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main(void)
{

int	ret_m;
int	ret_o;
setlocale(LC_ALL, "");
	double i[15];
	i[0] = 1315315615615615611.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000005;
	i[1] = 21474894;
	i[2] = 42.41916;
	i[3] = -80000;
	i[4] = -0.1 * 0;
	i[5] = -0.1;	
	i[6] = 153.999; // error (e)
	i[7] = -0.903002222; // 15.9
	i[8] = 24561789;
	i[9] = 0;
	i[10] = 42.42;
	i[11] = 1.5;
	i[12] = 15465.4654646;
	i[13] = 11321412;
	i[14] = 1.11120456;


int k = 0;

	ret_m = ft_printf("{%.G}", i[7]);
while (k < 15)
{
	ret_m = ft_printf("{%.G}", i[k]);
ft_putchar('\n');

	ret_o =    printf("{%.G}", i[k]);
fflush(stdout);
ft_putchar('\n');
	ft_printf("my = %10d, orig = %d\n", ret_m, ret_o);
	k++;
}
/*
		ft_printf("%015.9g\n", i);
	       printf("%015.9g\n", i);
		ft_printf("%+015E\n", i);
	       printf("%+015E\n", i);
		ft_printf("%0a\n", i);
	       printf("%0a\n", i);
		ft_printf("%0.f\n", i);
	       printf("%0.f\n", i);
*/
/*
        printf("%e\t%#e\t%010e\t%.7e\t%.e\n", d, d, d, d, d);
     ft_printf("%e\t%#e\t%010e\t%.7e\t%.e\n", d, d, d, d, d);
        printf("%f\t%#f\t%010f\t%.7f\t%.f\n", d, d, d, d, d);
        ft_printf("%f\t%#f\t%010f\t%.7f\t%.f\n", d, d, d, d, d);
	i = 42.41916;
	i = 0;
	i = -0.1;	
	i = 153.999;
	ft_printf("%hhd, %hhd\n", s[0], s[1]);
	ft_printf("%5d %.32b\n", c, c);
	s[1] = c << 2;
	s[1] = s[1] >> 2;
	s[0] = (c >> 6) + 192;
	ft_printf("c0%4hhu, %.8b\n", s[0], s[0]);
	ft_printf("c1%4hhu, %.8b\n", s[1], s[1]);
//	s[0] += 192;
	s[1] += 128;
	ft_printf("%5d %.32b\n", c, c);
	ft_printf("c0%4hhu, %.8b\n", s[0], s[0]);
	ft_printf("c1%4hhu, %.8b\n", s[1], s[1]);
*/	
/*	while (i < 3)
	{
		printf("org: %e\t", i);
		fflush(stdout);
		ft_printf("ft: %e\t\n", i);
		i = i + 0.01;
	}
*/	return (0);
}
