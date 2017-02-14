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

int		find_precision(long double nbr, t_arg *head, int nbr_len)
{
	if (head->precision != -1 && nbr - (long long)nbr == 0)
		head->precision = 0;
	else if (head->precision == -1 && nbr - (long long)nbr == 0)
		head->precision = 0;
	else if (head->precision == -1)
		head->precision = 4;
	else
		head->precision = head->precision - nbr_len;
	return (1);
}

char	*try_double(long double nbr, t_arg *head, int nbr_len)
{
	char	*str;
	int		i;
	int		buf_prec;

	buf_prec = head->precision;
//	if (head->precision < nbr_len)
//		return (NULL);
	if (head->precision == -1 && nbr_len > 6)
		return (NULL);
	find_precision(nbr, head, nbr_len);
	str = ft_itoa_d(nbr, head, -1);
	i = ft_strlen(str);
	while (i > 0 && str[i - 1] == '0' && head->precision != 0)
	{
		str[i - 1] = 0;
		i--;
	}
	head->precision = buf_prec;
	return (str);
}

char	*try_mod_e(long double nbr, t_arg *head, int nbr_len)
{
	if (nbr_len <= head->precision)
		return (NULL);
	if (head->precision < 0 && nbr_len > 6)	
		head->precision = 5;
	else if (head->precision < 0)
		head->precision += nbr_len - 1;
	else
		head->precision -= 1;
	return (mod_e(nbr, head));
}

char	*mod_g(long double nbr, t_arg *head)
{
	char	*str_e;
	char	*str_d;
	int		nbr_len;
	int		len_e;
	int		len_d;

	nbr_len = ft_nbrlen((long long)(nbr < 0 ? -nbr : nbr), 10);
	str_d = try_double(nbr, head, nbr_len);
	str_e = try_mod_e(nbr, head, nbr_len);
	if (str_d == NULL)
		return (str_e);
	if (str_e == NULL)
		return (str_d);
	ft_putstr(str_d);
	ft_putchar('\n');
	ft_putstr(str_e);
	ft_putchar('\n');
	len_e = ft_strlen(str_e);
	len_d = ft_strlen(str_d);
	if (len_d <= len_e)
		return (str_d);
	else
		return (str_e);
}
