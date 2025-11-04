#include "libft.h"

static int	ft_is_space(char c);

/*
Converts the initial portion of the string pointed to by str to int representation.
*/
int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				result;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
