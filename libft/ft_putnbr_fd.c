#include "libft.h"

static void	write_rec(long nbr, int fd);

/*
Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = (long) n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	write_rec(nbr, fd);
}

static void	write_rec(long nbr, int fd)
{
	char	c;

	if (nbr >= 10)
		write_rec(nbr / 10, fd);
	c = nbr % 10 + '0';
	write(fd, &c, 1);
}
