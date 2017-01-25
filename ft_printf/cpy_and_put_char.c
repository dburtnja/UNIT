
#include "ft_printf.h"

size_t	find_len(size_t strl, int p)
{
	if (p > 0 && p < strl)
		return (size_t)p;
	return (strl);	
}

char	*cpy_and_put_char(char *str, t_arg *head)
{
	size_t	len;
	size_t	i; 
	char	c;
	char	*ret;

	c = head->flag.nul > 0 ? '0' : ' ';
	len = find_len(ft_strlen(str), head->precision);
	ret = ft_strnew(len > head->width ? len : head->width);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	while (i < head->width)
	{
		ret[i] = c;
		i++;
	}
	return (ret);
}

char	*put_char_and_cpy(char *str, t_arg *head)
{
	size_t	len;
	size_t	w;
	size_t	i; 
	char	c;
	char	*ret;

	c = head->flag.nul > 0 ? '0' : ' ';
	len = find_len(ft_strlen(str), head->precision);
	w = len > head->width ? len : head->width;
	ret = ft_strnew(w);
	i = 0;
	while (i < w - len)
	{
		ret[i] = c;
		i++;
	}
	while (i < w)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

