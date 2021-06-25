#include "../ft_printf.h"

static int	recursive_pointer(size_t ber)
{
	if (ber == 0)
		return (0);
	else
		return (1 + recursive_pointer(ber / 16));
}

int	count_digits_ptr(void *ptr)
{
	size_t	ber;

	ber = (size_t) ptr;
	if (ber == 0)
		return (1);
	else
		return (recursive_pointer(ber));
}
