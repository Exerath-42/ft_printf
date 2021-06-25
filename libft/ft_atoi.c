#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	minus;

	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'\
		||str[i] == '\t' || str[i] == '\v')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			minus = -minus;
			i++;
		}
		else
			i++;
	}
	while (0 <= str[i] - '0' && str[i] - '0' <= 9)
		res = res * 10 + (str[i++] - '0');
	return (minus * res);
}
