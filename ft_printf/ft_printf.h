/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:02:03 by dburtnja          #+#    #+#             */
/*   Updated: 2017/02/08 14:26:41 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_flag
{
	int				pl;
	int				min;
	int				hesh;
	int				space;
	int				nul;
}					t_flag;

typedef	struct		s_arg
{
	struct s_arg	*next;
	int				mod;
	char			*data;
	t_flag			flag;
	int				width;
	int				precision;
	int				size;
	int				type;
	size_t			len;
}					t_arg;

int					ft_printf(char *str, ...);
long double			ft_ceil(long double nbr);
long double			ft_floor(long double nbr);
long double			ft_r_nbr(long double nbr);
int					lstlen(t_arg *head);
t_arg				*read_str(char *str, va_list arg);
int					colect_lst(t_arg **head, t_arg *lst);
t_arg				*new_lst(void *data, int f);
int					ft_print(t_arg *head);
t_arg				*check_type(char **str, va_list arg);
int					find_c(char c, char *str, int p);
int					check_width(char *str, int *i);
void				check_flags(char *str, int *i, t_flag *flag);
int					check_precision(char *str, int *i);
int					check_size(char *str, int *i);
int					find_type(char *str, int *type, int *i);
void				check_nbr(char *str, int *i, va_list arg, int *nbr);
int					read_arg(t_arg *head, va_list ptr);
void				mod_str(t_arg *head, va_list ptr);
char				*cpy_and_put_char(char *str, t_arg *head);
char				*put_char_and_cpy(char *str, t_arg *head);
void				ft_modlst(t_arg *head, va_list arg);
void				mod_char(t_arg *head, va_list ptr, char c);
void				mod_m_flag(char *str, t_arg *head);
void				mod_void(t_arg *head, va_list ptr);
void				mod_double(t_arg *head, va_list ptr);
void				mod_i_d(t_arg *head, va_list arg);
char				*ft_itoa_p(long long value, t_arg *head);
void				mod_unsigned(t_arg *head, va_list arg);
char				*ft_itoa_u(unsigned long long value, unsigned long long b,
t_arg *head, int up);
void				mod_n(t_arg *head, va_list arg);
char				*add_hesh(char *str, int b, int up);
size_t				find_len(size_t str, t_arg head);
size_t				find_size_str(size_t strl, t_arg *head, size_t *len);
char				*ft_round(long double nbr, t_arg *head, char *str);
char				*ft_itoa_d(long double value, t_arg *head, int power);
char				mk_sign(long long *value, t_arg *head, int *len);
char				mk_sign_d(long double *value, t_arg *head, int *len);
char				*all_len(int *len, t_arg *head, int power_s);
char				*add_nul(char *str, char sign, int len, char hesh);
void				mod_r(t_arg *head, va_list arg);
char				*mod_a(long double nbr, t_arg *head);
void				ft_round_d(long double nbr, t_arg *head, char *str);
int					h_check_flags(char check, char c, int *flag);
char				*proc_wint_t(int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_lentoc(char *buf, char c);
size_t				ft_putstr(char const *s);
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
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
char				*ft_strncpy(char *dest, const char *str, size_t n);
char				*ft_itoa_base(unsigned long long value, unsigned
		long long base, int up, int nul);
int					ft_nbrlen(unsigned long long i, unsigned long long base);
void				nbr_to_str(unsigned long long value, unsigned
		long long base, char **str, int up);

#endif
