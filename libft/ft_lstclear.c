#include "libft.h"

/*
Deletes and frees the given node and every successor of that node, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*next;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	*lst = NULL;
}
