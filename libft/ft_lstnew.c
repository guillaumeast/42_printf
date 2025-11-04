#include "libft.h"

/*
CALLER MUST FREE
---
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with the value of the parameter ’content’.
The variable ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}
