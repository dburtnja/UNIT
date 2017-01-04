/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:12:35 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/29 21:40:12 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	char *line;

	int fd;
	int	i;
	int	fd2;

	i = 1;
	fd = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	ft_putnbr(get_next_line(fd2, &line) > 0);
	ft_putendl(line);
	ft_putnbr(get_next_line(fd, &line) > 0);
	ft_putendl(line);
	ft_putnbr(get_next_line(fd2, &line) > 0);
	ft_putendl(line);
	while (i > 0)
	{
		i = get_next_line(fd, &line) > 0;
		ft_putnbr(i);
		ft_putstr(line);
	}
	return (0);
}
