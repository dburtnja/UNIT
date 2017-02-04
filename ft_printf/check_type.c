/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:03:13 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 21:11:15 by dburtnja         ###   ########.fr       */
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

int		find_type(char *str, int *type)
{
	char	*types;
	int		n;

	n = 0;
	types = "dDiuUoOxXbfFeEgGaAcCsSpnrk%";
	while ((*type = find_c(str[n], types, 0)) == 0)
	{
		if (str[n] == 0)
			return (0);
		n++;
	}
	if (str[n] == 0)
			return (0);
	return (n);
}

void	h_check_type(char *str, t_arg *new, int *i, va_list arg)
{
	int		j;
	int		b;

	j = *i;
	check_flags(str, i, &(new->flag));
	check_nbr(str, i, arg, &(new->width));
	if (str[*i] == '.')
	{
		(*i)++;
		new->precision = 0;
		check_nbr(str, i, arg, &(new->precision));
	}
	if ((b = check_size(str, i)) > new->size)
		new->size = b;
	if (*i == j)
		(*i)++;
}

t_arg	*check_type(char **str, va_list arg)
{
	int		i;
	int		type_place;
	t_arg	*new;

	i = 0;
	(*str)++;
	if ((new = new_lst(NULL, 1)) == NULL)
		exit (1);
	type_place = find_type(*str, &(new->type));
	while (type_place > i)
		h_check_type(*str, new, &i, arg);
	ft_modlst(new, arg);
	*str = *str + i + 1;
	return (new);
}
