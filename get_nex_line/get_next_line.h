/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:34:32 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/11 15:08:30 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_
# define BUFF_SIZE 20
# include "./libft/libft.h"

typedef	struct		s_line
{
	int				fd;
	char			*buf;
	int				f;
	struct s_line	*next;
}					t_line;
int		get_next_line(const int fd, char **line);

#endif
