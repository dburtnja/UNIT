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

	fd = open("file.txt", O_RDONLY);
	ft_putnbr(get_next_line(fd, &line));
	ft_putstr(line);
	return (0);
}
