/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:12:35 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/11 20:04:38 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	fd = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	ft_putnbr(fd);
	ft_putstr("\tfd2 = ");
	ft_putnbr(fd2);
	ft_putendl("\tSTART");


	

//	ft_putendl(line);
//	ft_putnbr(get_next_line(fd2, &line));
//	ft_putendl(line);
//	ft_putnbr(get_next_line(fd2, &line));
//	ft_putendl(line);
	while (i > 0 || j > 0)
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
	}
	return (0);
}
