#include "libft.h"

static void	recurse(long int num, int fd)
{
	if (num > 9)
		recurse(num / 10, fd);
	ft_putchar_fd('0' + num % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		num = n;
		if (num < 0)
		{
			write(fd, "-", 1);
			num = -num;
		}
		recurse(num, fd);
	}
}
