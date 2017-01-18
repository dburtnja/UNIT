
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
	int				flags;
	int				width;
	int				precision;
	char			size;
	char			type;
}					t_arg;

int					ft_printf(char *str, ...);
int					lstlen(t_arg *head);
t_arg				*read_str(char *str);
int					colect_lst(t_arg **head, t_arg *lst);
t_arg				*new_lst(void *data, int f);
int					mod_and_print(t_arg *head, int nbr);

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

#endif
