#include "../ft_printf.h"

int	ft_negative_check(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
