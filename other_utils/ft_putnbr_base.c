#include "../ft_printf.h"

static void	recursive(unsigned nb, unsigned base, char mode)
{
	int	rest;

	if (nb / base != 0)
		recursive(nb / base, base, mode);
	rest = nb % base;
	ft_putchar(convert(rest, mode));
}

void	ft_putnbr_base(unsigned nb, unsigned base, char mode)
{
	if (nb == 0)
		ft_putchar('0');
	else
		recursive(nb, base, mode);
}
