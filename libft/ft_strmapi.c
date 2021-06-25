#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	newstr = ft_strdup(s);
	if (!newstr)
		return (NULL);
	while (newstr[i])
	{
		newstr[i] = (*f)(i, newstr[i]);
		i++;
	}
	return (newstr);
}
