#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		((unsigned char *)dst)[i] = '\0';
	}
	return (ft_strlen(src));
}
