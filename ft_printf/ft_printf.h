
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_typ
{
	struct s_typ	*next;
	void			*data;
	char			flags;
	int				width;
	int				precision;
	char			size;
	char			type;


#endif
