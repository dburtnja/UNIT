#include <stdio.h>
#include <stdlib.h>

void	nbr_to_str(int value, int base)
{
	char c;

	if (value >= base)
	{
		nbr_to_str(value/base, base);
		nbr_to_str(value%base, base);
	}
	else
	{
		if (value > 9)
			c = value + 'A' - 10;
		else
			c = value + '0';
		printf("%c", c);
	}
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 33);
	nbr_to_str(value, base);
	
	return (str);
}

int		main(void)

	//printf("%d", 4 * 8);
	printf("\n%s", ft_itoa_base(255, 12));
	return (0);
}
