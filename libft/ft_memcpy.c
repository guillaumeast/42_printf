#include "libft.h"

/*
Copies n bytes from memory area src to memory area dst.
If dst and src overlap, behavior is undefined.

Returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
