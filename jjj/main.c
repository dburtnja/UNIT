/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:12:35 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/12 21:05:59 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_nex_line/get_next_line.h"
#include <fcntl.h>

int main(void)
{
	char *line;

	int fd = 1;
	int	i;
	int	j;
	int	fd2;
	ft_putstr("START\tfd = ");
	i = 1;
	j = 1;
	fd = open("../jjj/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("../jjj/file2.txt", O_RDONLY);
	ft_putnbr(fd);
	ft_putstr("\tfd2 = ");
	ft_putnbr(fd2);
	ft_putendl("\tSTART");


	

//	ft_putendl(line);
	while (get_next_line(fd, &line))
	ft_putstr(line);
//	ft_putnbr(get_next_line(fd2, &line));
//	ft_putendl(line);
/*	while (i > 0 || j > 0)
	{
		i = get_next_line(fd, &line);
		ft_putnbr(fd);
		ft_putchar('-');
		ft_putendl(line);
		j++;
		j = get_next_line(fd2, &line);
		ft_putnbr(fd2);
		ft_putchar('-');
		ft_putendl(line);
	}*/
	return (0);
}
