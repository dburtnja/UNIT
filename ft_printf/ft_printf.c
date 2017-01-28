/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:01:51 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/27 21:11:19 by dburtnja         ###   ########.fr       */
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
	char i;

	char s[] = "start end";
	ft_printf("ft_t: %#15.X\n", 220);
  	   printf("orig: %#15.X\n", 220);
	ft_printf("ft_t str: %15.5s\n", "admiral");
	ft_printf("ft_t add: %-20.p\n", &i);
  	   printf("orig add: %-20.p\n", &i);
	ft_printf("123456789%hhns\n", &i);
	ft_printf("ft_t n: %hhd\n", i);
	printf("123456789%hhns\n", &i);
	printf("ft_t n: %hhd\n", i);
	


//	ft_printf("my first printf:\a %d\n", 10, 10, 10, 10);
//	ft_putnbr(printf("\n   %denys  \n", 15));
	return (0);

}

