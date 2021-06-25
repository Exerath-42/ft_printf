#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = (t_list *)malloc(sizeof(content));
	if (!new_el)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
