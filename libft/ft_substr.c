#include "libft.h"

/*
CALLER MUST FREE
---
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	min_len;
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	min_len = ft_strlen(s + start);
	if (min_len < len)
		res = malloc(min_len + 1);
	else
		res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
