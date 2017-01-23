/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:03:13 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/20 22:21:05 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_c(char c, char *str, int p)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	if (p == 1)
		str[i] = c;
	return (0);
}

int		compare(int type, int size)
{
	if (size == 0)
		return (1);
	if ((type <= 6 || type == 18) && size < 8)
		return (1);
	else if (type <= 14 && size == 8)
		return (1);
	else if (type <= 16 && size == 3)
		return (1);
	return (0);
}

int		find_type(char *str, int *type)
{
	char	*types;
	int		n;

	n = 0;
	types = "diuoxXfFeEgGaAcspn";
	while ((*type = find_c(str[n], types, 0)) == 0)
	{
		n++;
		if (str[n] == 0)
			return (0);
	}
	return (n);
}

void	h_check_type(char *str, t_arg *new, int *i)
{
	int		j;
	int		b;

	j = *i;
	check_flags(str, i, &(new->flag));
	new->width = check_nbr(str, i, 0, &(new->w_star));
	new->precision = check_nbr(str, i, 1, &(new->p_star));
	if ((b = check_size(str, i)) > new->size && compare(new->type, b))
		new->size = b;
	if (*i == j)
		(*i)++;
}

t_arg	*check_type(char **str)
{
	int		i;
	int		type_place;
	t_arg	*new;

	i = 0;
	(*str)++;
	if (**str == '%')
	{
		(*str)++;
		return (new_lst(ft_strdup("%"), 0));
	}
	if ((new = new_lst(NULL, 1)) == NULL)
		exit (1);
	type_place = find_type(*str, &(new->type));
	while (type_place > i)
		h_check_type(*str, new, &i);
	*str = *str + i + 1;
	return (new);
}
