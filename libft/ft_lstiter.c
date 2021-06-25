#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*el;

	if (!f || !lst)
		return ;
	el = lst;
	while (el)
	{	
		f(el->content);
		el = el->next;
	}
}
