#include "libft.h"

static int	isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] !='\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed;

	if (!s1)
		return (NULL);
	i = 0;
	start = 0;
	while (s1[start] && isinset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && isinset(s1[end - 1], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start));
	if (!trimmed)
		return (NULL);
	while (start != end)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
