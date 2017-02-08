/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:21:59 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 14:26:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		h_check_flags(char check, char c, int *flag)
{
	if (check == c)
	{
		*flag = 1;
		return (1);
	}
	return (0);
}

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

int		find_type(char *str, int *type, int *i)
{
	char	*types;
	int		b;

	b = *type;
	types = "dDiuUoOxXbfFeEgGaAcCsSpnrk%";
	*type = find_c(str[*i], types, 0);
	if (*type != b)
		(*i)++;
	return (*type);
}

int		h_check_type(char *str, t_arg *new, int *i, va_list arg)
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
	if (find_type(str, &new->type, i) != 0 || *i == j)
		return (1);
	return (0);
}

t_arg	*check_type(char **str, va_list arg)
{
	int		i;
	t_arg	*new;

	i = 0;
	(*str)++;
	if ((new = new_lst(NULL, 1)) == NULL)
		exit(1);
	while (**str != 0)
	{
		if (h_check_type(*str, new, &i, arg) == 1)
			break ;
	}
	*str = *str + i;
	ft_modlst(new, arg);
	return (new);
}
