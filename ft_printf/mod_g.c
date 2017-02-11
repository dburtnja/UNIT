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
	if (head->precision == -1 && nbr - (long long)nbr == 0 && nbr_len > 6)
		head->precision = 6;
	else if (head->precision == -1 && nbr - (long long)nbr == 0)
		head->precision = 0;
	else if (head->precision == -1)
		head->precision = 4;
	else
		head->precision = head->precision - nbr_len;
	return (nbr_len);
}

char	*try_double(long double nbr, t_arg *head, int nbr_len)
{
	char	*str;
	int		i;

	find_precision(nbr, head, nbr_len);
	str = ft_itoa_d(nbr, head, -1);
	i = ft_strlen(str);
	while (i > 0 && str[i - 1] == '0' && head->precision != 0)
	{
		str[i - 1] = 0;
		i--;
	}
	return (str);
}

char	*try_mod_e(long double nbr, t_arg *head, int nbr_len)
{
	if (head->precision < 0 && nbr_len > 6)	
		head->precision == 5;
	else if (head->precision < 0)
		head->precision += nbr_len - 1;
	m_e = mod_e(nbr, head);
}

char	*mod_g(long double nbr, t_arg *head)
{
	char	*str_e;
	char	*str_d;
	int		nbr_len;
	int		len_e;
	int		len_d;

	nbr_len = ft_nbrlen((long long)(nbr < 0 ? -nbr : nbr), 10);
	str_e = try_mod_e(nbr, head, nbr_len);
	str_d = try_double(nbr, head, nbr_len);
	len_e = ft_strlen(str_e);
	len_d = ft_strlen(str_d);
	if (str_d == NULL)
		return (str_e);
	if (str_e == NULL)
		return (str_d);
	if (lene < ft_strlen(m_e)) && i >= 0)
		return (m_d);
	else
		return (m_e);
}
