
#include <unistd.h>
#include <stdlib.h>

void	brainfuck(char *s, char *a);

static void	clean(char *s)
{
	int		i;

	i = 0;
	while (i <= 5000)
	{
		s[i] = 0;
		i++;
	}
}

int			main(int argc, char **argv)
{
	int				i;
	char	*s;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	s = (char*)malloc(sizeof(char) * 5000);
	if (s)
	{
		clean(s);
		brainfuck(s, argv[1]);
	}
	return (0);
}
