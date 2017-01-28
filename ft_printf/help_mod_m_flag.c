
#include "ft_printf.h"

void	add_hesh(char *str, size_t *i, int hesh)
{
	if (hesh == 1)
	{
		str[*i] = '0';
		str[(*i) + 1] = 'x';
		*i += 2;
	}
}

size_t	find_len(size_t strl, t_arg head)
{
	int		   p;

	p = head.precision;
	if (head.flag.hesh == 1)
		return (strl + 2);
	if (p != -1 && (size_t)p < strl && head.type == 16)
		return (p);
	return (strl);
}

size_t	find_size_str(size_t strl, t_arg *head, size_t *len)
{
	*len = find_len(strl, *head);
	if (head->width != -1 && *len < (size_t)head->width)
		return ((size_t)head->width);
	else
		return (*len);
}
