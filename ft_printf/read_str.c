
#include "ft_printf.h"

t_arg	*check_type(char **str)
{
	t_arg	*new;
	char	flags[4] = "-+#0";
	char	type = "diuoxXf";

	return ();
}

t_arg	*read_str(char *str)
{
	t_arg	*head;
	t_arg	*p;
	int		start;
	int		i;

	start = 0;
	head = NULL;
	p = NULL;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			p = check_type(&str);
			colect_lst(&head, p);
		}
		else
		{
			p = new_lst(ft_strsub(str, 0, ft_lentoc(str, '%')), 1);
			colect_lst(&head, p);
			str = str + ft_lentoc(str, '%');
		}
	}
	return (head);
}

int		buf_printf()
{
	
	return (1);
}
