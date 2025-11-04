#include "libft.h"

/*
Locates the first occurrence of c (converted to a char) in the string pointed to by s.
The terminating null character is considered part of the string.
Therefore if c is ‘\0’, the functions locate the terminating ‘\0’.

Returns a pointer to the located character, or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char) c;
	while (*s)
	{
		if (*s == target)
			return ((char *) s);
		s++;
	}
	if (target == '\0')
		return ((char *) s);
	return (NULL);
}
