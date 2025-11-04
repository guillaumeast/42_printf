#include "libft.h"

static int	ft_is_in_charset(char const c, char const *set);

/*
CALLER MUST FREE
---
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_is_in_charset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_in_charset(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

static int	ft_is_in_charset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
