#include "libft.h"

char	*ft_add(char const *s, unsigned int start, size_t len, char *string)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (i == start)
		{
			while (s[i] && k < len)
				string[k++] = s[i++];
			string[k] = '\0';
			return (string);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	k;
	char	*string;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	string = malloc(sizeof(char) * ft_strlen(s + start));
	if (!string)
		return (NULL);
	if (!s[i] || start > ft_strlen(s))
	{
		string[0] = '\0';
		return (string);
	}
	return (ft_add(s, start, len, string));
}
