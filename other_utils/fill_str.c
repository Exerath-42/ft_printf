#include "../ft_printf.h"

void	fill_str(int c, int n)
{
	if (n >= 0)
		while (n--)
			ft_putchar(c);
}
