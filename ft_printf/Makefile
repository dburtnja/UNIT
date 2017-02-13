# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 16:49:11 by dburtnja          #+#    #+#              #
#    Updated: 2017/02/11 22:22:55 by dburtnja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC =	check_type.c\
		ft_atoi_mod.c\
		ft_bzero.c\
		ft_itoa_base.c\
		ft_itoa_p.c\
		ft_lentoc.c\
		ft_list.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_modlst.c\
		ft_nbrlen.c\
		ft_printf.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_strcat.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strncpy.c\
		ft_strnew.c\
		ft_strsub.c\
		help_check_type.c\
		help_mod_m_flag.c\
		mod_and_print.c\
		mod_char.c\
		mod_i_d.c\
		mod_m_flag.c\
		mod_n.c\
		mod_str.c\
		mod_unsigned.c\
		mod_double.c\
		mod_void.c\
		read_str.c\
		ft_round.c\
		mod_r.c\
		processing_wint_t.c\
		mod_a.c\
		mod_g.c\
		check_nbr.c\
		ft_itoa_d.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ)
		
clean:
		@rm -f $(OBJ)
		
fclean:
		@make clean
		@rm -f $(NAME)		
re:
		@make fclean
		@make all
		@ar rc $(NAME) $(OBJ)
