#include "../ft_printf.h"

void	ft_alignment(t_flags *flags, int spaces)
{
	if (flags -> dot && !flags -> precision_failed)
		fill_str(' ', spaces);
	else
		fill_str(' ' * (!(flags -> zero)) + '0' * (flags -> zero), spaces);
}
