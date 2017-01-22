/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:02:03 by dburtnja          #+#    #+#             */
/*   Updated: 2017/01/20 22:21:11 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_arg
{
	struct s_arg	*next;
	int				mod;
	void			*data;
	char			*flags;
	int				width;
	int				w_star;
	int				precision;
	int				p_star;
	int				size;
	int				type;
}					t_arg;

int					ft_printf(char *str, ...);
int					lstlen(t_arg *head);
t_arg				*read_str(char *str);
int					colect_lst(t_arg **head, t_arg *lst);
t_arg				*new_lst(void *data, int f);
int					mod_and_print(t_arg *head);
t_arg				*check_type(char **str);
int					find_c(char c, char *str, int p);
int					check_width(char *str, int *i);
char				*check_flags(char *str, int *i);
int					check_precision(char *str, int *i);
int					check_size(char *str, int *i);
int					find_type(char *str, int *type);
int					check_nbr(char *str, int *i, int f, int *star);
int					read_arg(t_arg *head, va_list ptr);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_lentoc(char *buf, char c);
int					ft_putstr(char const *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
char				*ft_strcat(char *dest, const char *src);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr(int n);
void				ft_putchar(char c);
int					ft_atoi_mod(char *buf, int *i);
char				*ft_strstr(const char *big, const char *little);

#endif
