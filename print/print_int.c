#include "../ft_printf.h"

static void	negative_case(t_flags *flags, int zeros, int spaces, int sign)
{
	if (sign)
		ft_putchar('-');
	fill_str('0', zeros);
	if (flags -> pure_width)
		ft_putnbr(*((int *)flags -> data));
	fill_str(' ', spaces);
}

static void	non_negative_case(t_flags *flags, int zeros,
		int spaces, int sign)
{
	if ((!flags -> dot || flags -> precision_failed) && flags -> zero)
	{
		if (sign)
			ft_putchar('-');
		ft_alignment(flags, spaces);
	}
	else
	{
		ft_alignment(flags, spaces);
		if (sign)
			ft_putchar('-');
	}
	fill_str('0', zeros);
	if (flags -> pure_width)
		ft_putnbr(*((int *)flags -> data));
}

int	print_int(t_flags *flags)
{
	int	zeros;
	int	spaces;
	int	sign;

	if (flags -> dot && !(*((unsigned *)flags -> data))
		&& !flags -> precision)
		flags -> pure_width = 0;
	sign = ((*((int *)flags -> data)) < 0);
	zeros = max(flags -> precision - flags -> pure_width, 0);
	spaces = max(flags -> width - zeros - flags -> pure_width - sign,
			0);
	if (flags -> minus)
		negative_case(flags, zeros, spaces, sign);
	else
		non_negative_case(flags, zeros, spaces, sign);
	return (zeros + spaces + flags -> pure_width + sign);
}
