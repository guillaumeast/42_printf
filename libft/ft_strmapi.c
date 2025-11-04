#include "libft.h"

/*
CALLER MUST FREE
---
Applies the function ’f’ to each character of the string ’s’.
Passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
