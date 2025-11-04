#include "libft.h"

/*
Compares byte string s1 against byte string s2.
Both strings are assumed to be n bytes long.

Returns zero if the two strings are identical, otherwise returns the difference between the first two differing bytes (treated as unsigned char values, so that ‘\200’ is greater than ‘\0’, for example).
Zero-length strings are always identical.
This behavior is not required by C and portable code should only depend on the sign of the returned value.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t		i;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	i = 0;
	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
