#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	b;
	char	*newstr;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		newstr = (char *)malloc(sizeof(char) * (size + 1));
		if (!newstr)
			return (NULL);
		i = 0;
		b = -1;
		while (s1[++b])
			newstr[i++] = s1[b];
		b = -1;
		while (s2[++b])
			newstr[i++] = s2[b];
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
