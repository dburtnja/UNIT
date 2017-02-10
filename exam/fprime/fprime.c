
#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int d;

	d = 2;
	if (nb <= 1)
	{
		printf("%d", nb);
		return ;
	}
	while (d <= nb)
	{
		if (nb % d == 0)
		{
			printf("%d", d);
			if (nb == d)
				return ;
			printf("*");
			nb = nb / d;
			d = 1;
		}
		d++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
}
