#include "../ft_printf.h"

int	print_char(t_flags *flags)
{
	int	spaces;

	spaces = max(flags -> width - flags -> pure_width, 0);
	if (flags -> minus)
	{
		ft_putchar(*((char *)flags -> data));
		fill_str(' ', spaces);
	}
	else
	{
		fill_str(' ' * (!(flags -> zero)) + '0' * (flags -> zero), spaces);
		ft_putchar(*((char *)flags -> data));
	}
	return (spaces + flags -> pure_width);
}
