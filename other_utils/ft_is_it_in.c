#include "../ft_printf.h"

int	is_it_in(char c, const char *str)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (1);
	return (0);
}
