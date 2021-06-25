#include "../ft_printf.h"

static int	recursive_int(int num)
{
	if (num == 0)
		return (0);
	else
		return (1 + recursive_int(num / 10));
}

int	count_digits(int num)
{
	if (num == 0)
		return (1);
	else
		return (recursive_int(num));
}
