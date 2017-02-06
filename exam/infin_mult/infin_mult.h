/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:04:31 by exam              #+#    #+#             */
/*   Updated: 2017/01/31 12:06:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_MULT_H
# define INFIN_MULT_H

# include <unistd.h>
# include <stdlib.h>

void    in_mult(char **argv, char **strs, int l1, int l2);
char    *res_null(char *str, int len);
void    move_int(char *str, int l1);
void    sum_strs(char **strs, int l1);

#endif
