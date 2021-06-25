#include "../ft_printf.h"

static void	rec(int n)
{
	if (n / 10 != 0)
		rec(n / 10);
	ft_putchar(ft_negative_check(n % 10) + '0');
}

void	ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else
		rec(n);
}
