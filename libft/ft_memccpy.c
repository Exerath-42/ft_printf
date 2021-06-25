#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)source)[i];
		if (((char *)source)[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
