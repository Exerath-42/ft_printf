#include "../ft_printf.h"

static int	recursive_unsigned(unsigned num, unsigned base)
{
	if (num == 0)
		return (0);
	else
		return (1 + recursive_unsigned(num / base, base));
}

int	count_unsigned_base(unsigned num, unsigned base)
{
	if (num == 0)
		return (1);
	else
		return (recursive_unsigned(num, base));
}
