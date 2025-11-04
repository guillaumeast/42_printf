#include "libft.h"

/*
CALLER MUST FREE
---
Contiguously allocates enough space for count objects that are size bytes of memory each and returns a pointer to the allocated memory.
The allocated memory is filled with bytes of value zero.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}
