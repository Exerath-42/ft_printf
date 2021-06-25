#include "../ft_printf.h"

void	*read_value(int conversion, va_list ap)
{
	if (conversion == 'd' || conversion == 'i' || conversion == 'c')
		return (read_int(ap));
	else if (conversion == 'p')
		return (read_pointer(ap));
	else if (conversion == 's')
		return (read_string(ap));
	else if (conversion == 'x' || conversion == 'X' || conversion == 'u')
		return (read_unsigned(ap));
	else if (conversion == '%')
		return (read_percent());
	return (NULL);
}
