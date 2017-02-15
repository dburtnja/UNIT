/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 mod_g.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: dburtnja <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/02/11 22:21:00 by dburtnja		   #+#	  #+#			  */
/*	 Updated: 2017/02/11 22:21:00 by dburtnja		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "ft_printf.h"

char	*try_double(long double nbr, t_arg *head, int nbr_len)
{
	char	*str;
	int		i;
	int		prec;

	prec = head->precision;
	if (head->precision == -1)
		head->precision = 6;
	else if (head->precision >= nbr_len)
		head->precision = head->precision - nbr_len;
	else if (head->precision < nbr_len)
		return (NULL);
	str = ft_itoa_d(nbr, head, -1);
	i = ft_strlen(str);
	while (i > 0 && str[i - 1] == '0' && head->precision != 0)
	{
		str[i - 1] = 0;
		i--;
	}
	if (str[i - 1] == '.')
		str[i - 1] = 0;
	head->precision = prec;
	return (str);
}

int		only_nbr_len(char *str)
{
	int		i;

	i = 0;
	while ((str[i] != 0 && str[i] >= '0' && str[i] <= '9') || str[i] == '-' ||
		str[i] == '.')
		i++;
	return (i);
}

void	rem_nul(char *str)
{
	int		i;
	char	*p;

	i = only_nbr_len(str);
	p = str + i - 1;
	while (*p == '0' && p != str)
		p--;
	ft_memmove((void*)p + 1, (void*)str + i, (ft_strlen(str) - i) + 1);
}

char	*try_mod_e(long double nbr, t_arg *head)
{
	int		prec;
	char	*str;

	prec = head->precision;
	if (head->precision == -1)
		head->precision = 5;
	str = mod_e(nbr, head);
	rem_nul(str);
	head->precision = prec;
	return (str);
}

char	*mod_g(long double nbr, t_arg *head)
{
	char	*str_e;
	char	*str_d;
	int		nbr_len;
	int		len_e;
	int		len_d;

	if ((long long)nbr == 0 && head->precision == 0)
		head->precision = 1;
	nbr_len = ft_nbrlen((long long)(nbr < 0 ? -nbr : nbr), 10);
	str_e = try_mod_e(nbr, head);
	if ((str_d = try_double(nbr, head, nbr_len)) == NULL)
		return (str_e);
	len_e = only_nbr_len(str_e);
	len_d = only_nbr_len(str_d);
	if (len_d <= len_e)
		return (str_d);
	else
		return (str_e);
}
