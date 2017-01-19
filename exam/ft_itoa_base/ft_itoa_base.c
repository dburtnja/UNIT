#include <stdio.h>
#include <stdlib.h>

void	nbr_to_str(unsigned int value, unsigned int base, char **str)
{
	char c;

	if (value >= base)
	{
		nbr_to_str(value/base, base, str);
		nbr_to_str(value%base, base, str);
	}
	else
	{
		if (value > 9)
			c = value + 'A' - 10;
		else
			c = value + '0';
		**str = c;
		(*str)++;
	}
	**str = '\0';
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*s;
	
	str = (char*)malloc(sizeof(char) * 33);
	*str = 0;
	s = str;
	if (value < 0)
	{
		if (base == 10)
		{
			*str = '-';
			str++;
		}
		value *= -1;	
	}
	if (base < 2 || base > 16)
		return (s);
	nbr_to_str((unsigned int)value, (unsigned int)base, &str);
	return (s);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	//printf("%d", 4 * 8);
	printf("%s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	
	return (0);
}
