
#include "brainfuck.h"

char	*brainfuck(char **str, char *map)
{
	int		i;
	char	*p;

	i = 0;
	while (*map != ']' && *map != 0)
	{
		if (*map == '>') (*str)++;
		else if (*map == '<') (*str)--;
		else if (*map == '+') (**str)++;
		else if (*map == '-') (**str)--;
		else if (*map == '.') write(1, *str, 1);
		else if (*map == '[')
		{
			if (**str == 0)
			{
				while (1)
				{
					if (*map == '[')
						i++;
					if (*map == ']')
						i--;
					if (i <= 0)
						break ;
					map++;
				}
			}
			else
			{
				p = brainfuck(str, map + 1);
				if (p)
					map = p;
				else
					map--;
			}
		}
		map++;
	}
	if (**str == 0)
		return (map);
	return (NULL);
}

int		main(int argc, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	if (argc == 2)
	{
		str = (char*)malloc(sizeof(char) * 5000);
		while (i < 5000)
		{
			str[i] = 0;
			i++;
		}
		brainfuck(&str, argv[1]);
	}
	return (0);
}
