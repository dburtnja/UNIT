/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:01:51 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/19 14:02:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	t_arg	*head;
	int		count;
	va_list arg_ptr;

	if (!str)
		return (-1);
	count = 0;
	head = read_str(str);
	va_start(arg_ptr, str);
	read_arg(head, arg_ptr);	
/*	while (count < nbr)
	{
		printf("%d\n", va_arg(arg_ptr, int));
		count++;
	}*/
	va_end(arg_ptr);
	return (mod_and_print(head));
}

#include <stdio.h>
int main(void)
{
	ft_putnbr(ft_printf("%s under%sscore,%s\n", " str ", "vholodin", "okres"));
//	ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	ft_putnbr(printf("\n   %denys  \n", 15));
	return (0);

}

