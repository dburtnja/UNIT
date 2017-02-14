
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*rev_str(char *str, int *len)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i])
		i++;
	*len += i;
	ret = (char*)malloc(i + 1);
	ret[i] = 0;
	while (*str)
	{
		ret[i - 1] = (*str - '0');
		str++;
		i--;
	}
	return (ret);
}

char	*mult_nbrs(int *res, char *str1, char *str2, int len)
{
	int		i;
	int		j;

	i = 0;
	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			res[i + j - 1] += str1[i] * str2[j];
			j++;
		}
		i++;
	}

	int k = i + j;
	while (k > 0)
	{
		printf("%5d", res[k]);
		k--;
	}
	return (str1);	
}			

char	*infin_mult(char **argv)
{
	int		*ret;
	char	*str1;
	char	*str2;
	int		len;
	int		i;

	i = 0;
	len = 1;
	str1 = rev_str(argv[1], &len);
	str2 = rev_str(argv[2], &len);
	ret = (int*)malloc(sizeof(int) * len);
	while (i < len)
	{
		ret[i] = 0;
		i++;
	}
	mult_nbrs(ret, str1, str2, len);
	return (str1);
}

int		main(int argc, char **argv)
{
	char	*res;

	if (argc == 3)
	{
		res = infin_mult(argv);
	}
	write(1, "\n", 1);
	return (0);
}
