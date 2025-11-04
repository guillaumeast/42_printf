#include "libft.h"

static size_t	get_len(int	n);
static void		populate(int n, char *str, size_t i);

/*
CALLER MUST FREE
---
Allocates (with malloc(3)) and returns a string representing the integer received as an argument.
Negative numbers must be handled.
*/
char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	len = get_len(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	populate(n, res, len - 1);
	return (res);
}

static size_t	get_len(int	n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	populate(int n, char *str, size_t i)
{
	int	mod;

	if (n >= 10 || n <= -10)
		populate(n / 10, str, i - 1);
	mod = n % 10;
	if (mod < 0)
		mod *= -1;
	str[i] = mod + '0';
}
