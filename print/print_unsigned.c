#include "../ft_printf.h"

int	print_unsigned(t_flags *flags, unsigned int base, char mode)
{
	int	zeros;
	int	spaces;

	if (flags -> dot && !(*((unsigned *)flags -> data))
		&& !flags -> precision)
		flags -> pure_width = 0;
	zeros = max(flags -> precision - flags -> pure_width, 0);
	spaces = max(flags -> width - zeros - flags -> pure_width, 0);
	if (flags -> minus)
	{
		fill_str('0', zeros);
		if (flags -> pure_width)
			ft_putnbr_base(*((unsigned *)flags -> data), base, mode);
		fill_str(' ', spaces);
	}
	else
	{
		ft_alignment(flags, spaces);
		fill_str('0', zeros);
		if (flags -> pure_width)
			ft_putnbr_base(*((unsigned *)flags -> data), base, mode);
	}
	return (zeros + spaces + flags -> pure_width);
}
