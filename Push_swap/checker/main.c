
#include "../lib/Push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int		check_if_num(char *str)
{
	int 	nbr;

	nbr = ft_atoi(str);
	if (ft_strcmp(ft_itoa(nbr), str) != 0)
		error();
	return (nbr);
}

t_doub_lst	*make_lst(int size, char **arg)
{
	int			i;
	t_doub_lst	*p;
	t_doub_lst	*head;

	i = 0;
	head = NULL;
	while (i < size)
	{
		p = new_lst(check_if_num(arg[i]));
		add_lst_to_back(&head, p);
		i++;
	}
	head->size = size;
	return (head);
}

void	check_flag(int *flag, char ***argv, int *argc)
{
	char	**p_argv;

	*flag = 0;
	p_argv = *argv;
	p_argv++;
	(*argc)--;
	if (*argc > 1 && p_argv[0][0] == '-' && p_argv[0][1] == 'v')
	{
		*flag = 1;
		(*argc)--;
		p_argv++;
	}
	*argv = p_argv;
}

int		main(int argc, char **argv)
{
	t_doub_lst	*a;
	t_doub_lst	*b;
	int 		flag;

	b = NULL;
	if (argc > 1)
	{
		check_flag(&flag, &argv, &argc);
		a = make_lst(argc, &argv[0]);
		write(1, check_instructions(&a, &b, flag) == 1 ? "OK\n" : "KO\n", 3);
		free_lst(&a);
		if (b)
			free_lst(&b);
	}
	return 0;
}