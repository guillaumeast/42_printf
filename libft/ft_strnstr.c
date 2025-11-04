#include "libft.h"

/*
Locates the first occurrence of the null-terminated string needle in the string haystack.
Not more than len characters are searched.
Characters that appear after a ‘\0’ character are not searched.
Since the strnstr() function is a FreeBSD specific API, it should only be used when portability is not a concern.

If needle is an empty string, haystack is returned.
If needle occurs nowhere in haystack, NULL is returned
Otherwise a pointer to the first character of the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *) (haystack + i));
		i++;
	}
	return (NULL);
}
