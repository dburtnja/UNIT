
#include "checker.h"

void    error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

int     check_if_num(char *str, int *nbr)
{
    *nbr = ft_atoi(str);
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        str++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int     *a;
    int     *b;
    int     i;

    i = 0;
    a = (int*)malloc(sizeof(int) * (argc - 1));
    b = (int*)malloc(sizeof(int) * (argc - 1));
    if (argc > 1)
    {
        while (i < argc)
        {
            if (check_if_num(argv[i + 1], &a[i]) == 0)
                error();
            i++;
        }

    }
    return 0;
}