#include "libft.h"

/*
Locates the first occurrence of c (converted to an unsigned char) in string s.

Returns a pointer to the byte located, or NULL if no such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		target;
	const unsigned char	*str;
	size_t				i;

	target = (unsigned char) c;
	str = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) str[i] == target)
			return ((void *) (str + i));
		i++;
	}
	if (target == '\0')
		return ((void *) (str + i));
	return (NULL);
}
