
#include "ft_printf.h"

void	find_type_mod(t_arg *head, va_list arg)
{
/*	if (head->type <= 2)
		mod_i_d(head, arg);
	else if (head->type <= 6)
		mod_u_o_x(head, arg);
	else if (head->type <= 14)
		mod_f_e_g_a(head, arg);
	else if (head->type == 15)
		mod_char(head, arg);
	else */if (head->type == 16)
		mod_str(head, arg);
/*	else if (head->type == 17)
		mod_void(head, arg);
	else if (head->type == 18)
		mod_n(head, arg);*/
}

void	ft_modlst(t_arg *head, va_list arg)
{
	while (head)
	{
		if (head->mod == 1 && head->type > 0)
			find_type_mod(head, arg);
		head = head->next;
	}
}
