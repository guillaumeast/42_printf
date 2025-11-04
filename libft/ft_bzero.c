#include "libft.h"

/*
Writes n zeroed bytes to the string s.
If n is zero, bzero() does nothing.
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
