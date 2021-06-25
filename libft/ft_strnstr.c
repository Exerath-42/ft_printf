#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	if (!*needle)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	while (*haystack != '\0' && nlen <= len--)
	{
		if (ft_memcmp(haystack, needle, nlen) == 0)
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
