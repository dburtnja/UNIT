
#include <unistd.h>

void	put_16(unsigned char c)
{
	unsigned char	b;

	if (c == 0)
		write(1, "0", 1);
	if (c >= 16)
	{
		put_16(c / 16);
		put_16(c % 16);
	}
	else
	{
		if (c < 9)
			b = c + '0';
		else
			b = (c - 10) + 'a';
		write(1, &b, 1);
	}
}

void	write_str(unsigned char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (s[i] > 31 && s[i] < 127)
			write(1, &s[i], 1);
		else
			write (1, ".", 1);
		i++;
	}
	write (1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char*)addr;
	i = 0;
	while (i < size)
	{
		put_16(s[i]);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
			write_str(&s[i - 16], size - i);
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
		              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
