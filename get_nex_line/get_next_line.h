/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 15:34:32 by dburtnja          #+#    #+#             */
/*   Updated: 2016/12/29 21:55:44 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_
# define BUFF_SIZE 12
# include "../libft/libft.h"
typedef	struct		s_line
{
	char			*buff;
	t_list			*new;
	t_list			*head;
	t_list			*ptr;
	int				i;
}					t_line;
int		get_next_line(const int fd, char **line);

#endif
