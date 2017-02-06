
#include "brainfuck.h"

char	*brainfuck(char **str, char *map)
{
	char	*buf;
	int		i;

	i = 0;
	while (*map != 0 && *map != ']')
	{
		if (*map == '+') (**str)++;
		else if (*map == '-') (**str)--;
		else if (*map == '>') (*str)++;
		else if (*map == '<') (*str)--;
		else if (*map == '.') write(1, *str, 1);
		else if (*map == '[')
		{
			if (**str == 0)
			{
/*				while (1)
				{
					if (*map == '[')
						i++;
					if (*map == ']')
						i--;
					if (i == 0)
						break;
					map++;
				}
*/			}
			else
			{
				buf = brainfuck(str, map + 1);
				map = buf ? buf : map - 1;	
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
	else
		write(1, "\n", 1);
	return (0);
}
