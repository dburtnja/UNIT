/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:03:13 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/20 19:20:20 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_c(char c, char *str, int p)
{
	while (*str != 0)
	{
		if (*str == c)
			return (1);
		str++;
	}
	if (p == 1)
		*str = c;
	return (0);
}

int		compare(int type, int size)
{
	if (size == 0)
		return (1);
	if (type <= 6 && size < 8)
		return (1);
	else if (type <= 14 && size == 8)
		return (1);
	else if (type <= 16 && size == 3)
		type_n = 3;
	type_n = type - 11;
}

t_arg	*check_type(char **str)
{
	int		i;
	int		b;
	int		type_place;
	t_arg	*new;

	i = 0;
	new = new_lst(NULL, 0);
	if (!new)
		exit (1);
	type_place = find_type(*str, &new->type);
	while (
	new->flags = check_flags(*str, &i);
	new->width = check_nbr(*str, &i, 0);
	new->precision = check_nbr(*str, &i, 1);
	if ((b = check_size(*str, &i)) > new->size && compare(new->type, b))
		new->size = b;
	return (new);
}
