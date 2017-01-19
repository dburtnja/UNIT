
#include <unistd.h>

void	print_memory(const void *addr, size_t size);

char	*brainfuck(char **s, char *a)
{
	char	*p;
	int		i;

	i = 0;
	while (*a != 0 && *a != ']')
	{
		if (*a == '>')
			(*s)++;
		else if (*a == '<')
			(*s)--;
		else if (*a == '+')
			(**s)++;
		else if (*a == '-')
			(**s)--;
		else if (*a == '.')
			write(1, *s, 1);
		else if (*a == '[')
		{
			if (**s == 0)
			{
				while (1)
				{
					if (*a == '[')
						i++;
					if (*a == ']')
						i--;
					if (i <= 0)
						break ;
					a++;
				}
			}
			else
			{
				p = brainfuck(s, a + 1);
				if (p != NULL)
					a = p;
				else
					a--;
			}
		}
		a++;
	}
	if (**s == 0)
		return (a);

	return (NULL);
}


