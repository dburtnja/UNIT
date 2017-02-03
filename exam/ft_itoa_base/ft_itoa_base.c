#include <stdio.h>
#include <stdlib.h>

void	nbr_to_str(unsigned long long value, unsigned long long base, char **str, int up)
{
	char c;

	if (value >= base)
	{
		nbr_to_str(value/base, base, str, up);
		nbr_to_str(value%base, base, str, up);
	}
	else
	{
		if (value > 9)
			c = value + (up == 0 ? 'a' : 'A') - 10;
		else
			c = value + '0';
		**str = c;
		(*str)++;
	}
	**str = '\0';
}

char	*ft_itoa_base(unsigned long long value, unsigned long long base, int up)
{
	char	*str;
	char	*s;
	
	str = (char*)malloc(sizeof(char) * 65);
	*str = 0;
	s = str;
/*	if (value < 0)
	{
		if (base == 10)
		{
			*str = '-';
			str++;
		}
		value *= -1;	
	}*/
	if (base < 2 || base > 16)
		return (s);
	nbr_to_str(value, base, &str, up);
	return (s);
}

int		main(void)
{
	int		i = 0;
	int		*pi = &i;
	unsigned long long		val = (unsigned long long)pi;
	
	printf("%p\n", pi);
	printf("%#llx\n", val);
	printf("%s\n", ft_itoa_base(val, 16, 0));
	
	return (0);
}
