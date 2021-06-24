#include "../ft_printf.h"

int	print(t_flags *flags)
{
	if (flags -> conversion == 'd' || flags -> conversion == 'i')
		return (print_int(flags));
	else if (flags -> conversion == 'x')
		return (print_unsigned(flags, 16, 'x'));
	else if (flags -> conversion == 'X')
		return (print_unsigned(flags, 16, 'X'));
	else if (flags -> conversion == 'u')
		return (print_unsigned(flags, 10, 'x'));
	else if (flags -> conversion == 'c' || flags -> conversion == '%')
		return (print_char(flags));
	else if (flags -> conversion == 's')
		return (print_string(flags));
	else if (flags -> conversion == 'p')
		return (print_pointer(flags));
	return (0);
}
