/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:20:15 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:33:52 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_rec(long nbr, int fd);

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
