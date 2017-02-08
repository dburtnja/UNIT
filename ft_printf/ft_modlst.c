/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 15:58:50 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 15:58:52 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_modlst(t_arg *head, va_list arg)
{
	if (head->type == 0)
		head->data = ft_strdup("");
	else if (head->type <= 3)
		mod_i_d(head, arg);
	else if (head->type <= 10)
		mod_unsigned(head, arg);
	else if (head->type <= 18)
		mod_double(head, arg);
	else if (head->type <= 20)
		mod_char(head, arg, 0);
	else if (head->type <= 22)
		mod_str(head, arg);
	else if (head->type == 23)
		mod_void(head, arg);
	else if (head->type == 24)
		mod_n(head, arg);
	else if (head->type == 25)
		mod_r(head, arg);
/*	else if (head->type == 26)
		mod_k(head, arg);
*/	else if (head->type == 27)
		mod_char(head, arg, '%');
}
