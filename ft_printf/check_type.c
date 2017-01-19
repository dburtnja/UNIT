/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:03:13 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/19 21:57:05 by dburtnja         ###   ########.fr       */
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

t_arg	*check_type(char **str)
{
	int		i;
	t_arg	*new;

	i = 0;
	new = new_lst(NULL, 0);
	if (!new)
		exit (1);
	new->flags = check_flags(*str, &i);
	new->width = check_nbr(*str, &i);
	if (str[0][*i] == '.')
		new->precision = check_nbr(*str, &i);
	new->size = check_size(*str, &i);
	return (new);
}
