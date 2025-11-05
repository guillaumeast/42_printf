#include "libftprintf.h"

static void	write_rec(long nbr, ssize_t *count);
static void	write_urec(unsigned int nbr, ssize_t *count);

int	ft_putnbr(int n)
{
	ssize_t	count;
	long	nbr;

	count = 0;
	nbr = (long) n;
	if (nbr < 0)
	{
		count = write(1, "-", 1);
		if (count < 0)
			return (-1);
		nbr *= -1;
	}
	write_rec(nbr, &count);
	return ((int) count);
}

static void	write_rec(long nbr, ssize_t *count)
{
	ssize_t written;
	char	c;

	if (nbr >= 10)
		write_rec(nbr / 10, count);
	c = nbr % 10 + '0';
	written = write(1, &c, 1);
	if (written > 0)
		*count += written;
}

int	ft_putunbr(unsigned int n)
{
	ssize_t	count;

	count = 0;
	write_urec(n, &count);
	return ((int) count);
}

static void	write_urec(unsigned int nbr, ssize_t *count)
{
	ssize_t written;
	char	c;

	if (nbr >= 10)
		write_rec(nbr / 10, count);
	c = nbr % 10 + '0';
	written = write(1, &c, 1);
	if (written > 0)
		*count += written;
}
