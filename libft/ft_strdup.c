#include "libft.h"

static	void	ft_strcpy(char *dst, const char *src);

/*
CALLER MUST FREE
---
Allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.
If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
*/
char	*ft_strdup(const char *s1)
{
	char	*res;

	res = malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	return (res);
}

static	void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
