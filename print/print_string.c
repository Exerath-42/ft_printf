#include "../ft_printf.h"

static int	nullcase(t_flags *flags, int spaces, int len)
{
	if (flags -> minus)
	{
		ft_putstr_custom("(null)", len);
		fill_str(' ', spaces);
	}
	else
	{
		fill_str(' ' * (!(flags -> zero)) + '0' * (flags -> zero), spaces);
		ft_putstr_custom("(null)", len);
	}
	return (spaces + len);
}

int	print_string(t_flags *flags)
{
	int	spaces;
	int	len;

	if (flags -> dot)
		len = min(flags -> precision, flags -> pure_width);
	else
		len = flags -> pure_width;
	spaces = max(flags -> width - len, 0);
	if (!(*((char **)flags -> data)))
		return (nullcase(flags, spaces, len));
	if (flags -> minus)
	{
		ft_putstr_custom(*((char **)flags -> data), len);
		fill_str(' ', spaces);
	}
	else
	{
		fill_str(' ' * (!(flags -> zero)) + '0' * (flags -> zero), spaces);
		ft_putstr_custom(*((char **)flags -> data), len);
	}
	return (spaces + len);
}
