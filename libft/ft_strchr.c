#include "libft.h"

char 	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (i < (int)ft_strlen(s) + 1)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
