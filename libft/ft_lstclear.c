#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*el;

	if (!del || !lst)
		return ;
	while (*lst)
	{	
		el = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = el;
	}
}
