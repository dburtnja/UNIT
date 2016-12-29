
#include <unistd.h>

char	*brainfuck(char *s, char *a)
{
	char	*p;

	while (*a != 0 && *a != ']')
	{
		if (*a == '>')
			s++;
		else if (*a == '<')
			s--;
		else if (*a == '+')
			(*s)++;
		else if (*a == '-')
			(*s)--;
		else if (*a == '.')
			write(1, s, 1);
		else if (*a == '[')
		{
			p = brainfuck(s, a + 1);
			if (p != NULL)
				a = p;
			else
				a--;
		}
		a++;
	}
	if (*s == 0)
		return (a);
	return (NULL);
}


