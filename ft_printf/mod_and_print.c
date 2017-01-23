
#include "ft_printf.h"
#include <stdio.h>

void	find_type_mod(t_arg *head)
{
	if (head->type <= 2)
		mod_i_d(head);
	else if (head->type <= 6)
		mod_u_o_x(head);
	else if (head->type <= 14)
		mod_f_e_g_a(head);
	else if (head->type == 15)
		mod_char(head);
	else if (head->type == 16)
		mod_str(head);
	else if (head->type == 17)
		mod_void(head);
	else if (head->type == 18)
		mod_n(head);
}

void	ft_modlst(t_arg *head)
{
	while (head)
	{
		if (head->mod == 1 && head->type > 0)
			find_type_mod(head);
		head = head->next;
	}
}

int		mod_and_print(t_arg *head)
{
	char	*str;
	char	*new;

	str = ft_strnew(0);
	ft_modlst(head);
	while (head)
	{
		new = ft_strjoin(str, (char*)head->data);
		ft_memdel(&(head->data));
		ft_strdel(&str);
		str = new;
		head = head->next;
	}
	return (ft_putstr(str));
}
