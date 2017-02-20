
#include "../lib/Push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int		check_if_num(char *str, int *nbr)
{
	*nbr = ft_atoi(str);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int		*new_int_array(int size)
{
	int *array;
	int i;

	i = 0;
	array = (int *) malloc(sizeof(int) * size);
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

int		main(int argc, char **argv)
{
	int *a;
	int *b;
	int i;

	i = 1;
	a = new_int_array(argc);
	b = new_int_array(argc);
	*a = argc - 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (check_if_num(argv[i], &a[i]) == 0)
				error();
			i++;
		}

	}
	return 0;
}