#include "libft.h"

static int	check_len(int n, int sign)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	if (len == 0)
		return (1 + sign);
	else
		return (len + sign);
}

static char	*convert(int nlen, int sign, int n)
{
	char	*c;

	c = (char *)malloc((sizeof(char) * nlen + 1));
	if (!c)
		return (NULL);
	c[nlen] = '\0';
	while (--nlen >= sign)
	{
		c[nlen] = n % 10 + 48;
		n = n / 10;
	}
	if (nlen >= 0)
		c[nlen] = '-';
	return (c);
}

char	*ft_itoa(int n)
{
	int		nlen;
	char	*a;
	int		sign;

	nlen = 0;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	nlen = check_len(n, sign);
	a = convert(nlen, sign, n);
	return (a);
}
