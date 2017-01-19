
#include <unistd.h>

void	put_16(unsigned char c)
{
	if (c >= 16)
	{
		put_16(c / 16);
		put_16(c % 16);
	}
	else
	{
		if (c < 10)
			c = c + '0';
		else
			c = c + 'a' - 10;
		write(1, &c, 1);
	}
}

void	print_char(unsigned char c)
{
	if (c > 31 && c < 127)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

void	spaces(size_t i)
{
	i = (16 - i) * 2;
	write (1, " ", 1);
	while (i > 0)
	{
		if (i % 4 == 0)
			write (1, " ", 1);
		write (1, " ", 1);
		i--;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)addr;
	while (i < size)
	{
		if (i % 16 == 0)
			j = i;
		if (str[i] < 16)
			write(1, "0", 1);
		put_16(str[i]);
		i++;
		if (i % 16 == 0 || size == i)
		{
			spaces(i - j);
			while (j < i)
			{
				print_char(str[j]);	
				j++;
			}
			write(1, "\n", 1);
		}
		else if (i % 2 == 0)
			write(1, " ", 1);
	}
}

