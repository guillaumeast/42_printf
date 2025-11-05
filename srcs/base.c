#include "libftprintf.h"

static void	print_rec(unsigned int nbr, const char *base, ssize_t *count);

int	ft_putnbr_hex(unsigned int nbr, t_bool uppercase)
{
	ssize_t		count;
	const char	*base;

	count = 0;
	if (uppercase)
		base = HEX_UPP_BASE;
	else
	 	base = HEX_LOW_BASE;
	print_rec(nbr, base, &count);
	return ((int) count);
}

static void	print_rec(unsigned int nbr, const char *base, ssize_t *count)
{
	int		i;
	char	c;
	ssize_t	written;

	if (nbr >= HEX_BASE_LEN)
		print_rec(nbr / HEX_BASE_LEN, base, count);
	i = nbr % HEX_BASE_LEN;
	c = base[i];
	written = write(1, &c, 1);
	if (written > 0)
		*count += written;
}
