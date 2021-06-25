#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*m;

	m = malloc(count * size);
	if (!m)
		return (NULL);
	ft_bzero(m, count * size);
	return (m);
}
