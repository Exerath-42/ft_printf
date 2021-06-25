#include "../ft_printf.h"

int	print_pointer(t_flags *flags)
{
	int	spaces;

	spaces = max(flags -> width - flags -> pure_width, 0);
	if (flags -> minus)
	{
		ft_putptr(*((void **)flags -> data));
		fill_str(' ', spaces);
	}
	else
	{
		fill_str(' ' * (!(flags -> zero)) + '0' * (flags -> zero), spaces);
		ft_putptr(*((void **)flags -> data));
	}
	return (spaces + flags -> pure_width);
}
