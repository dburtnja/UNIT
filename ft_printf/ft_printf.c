#include "../libft/libft.h"

int		ft_printf(const char *restrict format, ...)
{
	void **s = (void**)&format;
	ft_putstr(format);
	s++;
	ft_putstr(*s);
	return (0);
}

int main(void)
{
	ft_printf("aaa %s \n %s\n", "first", "second");
	return (0);
}
