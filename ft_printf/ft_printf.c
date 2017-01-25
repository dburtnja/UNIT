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
	int		ret;
	va_list arg_ptr;

	if (!str)
		return (-1);
	va_start(arg_ptr, str);
	head = read_str(str, arg_ptr);
	ret = ft_print(head);
	va_end(arg_ptr);
	return (ret);
}

#include <stdio.h>
int main(void)
{
	ft_printf("%s under%sscore,%s\n", " str ", "vholodin", "okres");
	printf("%s under%sscore,%s\n", " str ", "vholodin", "okres");

//	ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	ft_putnbr(printf("\n   %denys  \n", 15));
	return (0);

}

