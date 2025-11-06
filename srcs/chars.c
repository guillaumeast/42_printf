#include "libftprintf.h"

int	ft_putchar(int c)
{
	unsigned char uc;

	uc = (unsigned char) c;
	return ((int) write(1, &uc, 1));
}

int	ft_putstr(char *str)
{
	ssize_t	written;
	ssize_t	count;
	int		i;

	if (!str)
		return ((int) write(1, "(null)", 6));
	count = 0;
	i = 0;
	while (str[i])
	{
		written = write(1, &(str[i]), 1);
		if (written < 0)
			return (-1);
		count += written;
		i++;
	}
	return ((int) count);
}
