#include "libft.h"

size_t 	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	dstlen;
	size_t	res;
	size_t	srclen;
	size_t	i;

	s = (char *)src;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(s);
	res = 0;
	i = 0;
	if (dstsize > dstlen)
		res = srclen + dstlen;
	else
		res = srclen + dstsize;
	while (s[i] && (dstlen + 1) < dstsize)
	{
		dst[dstlen] = s[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (res);
}
