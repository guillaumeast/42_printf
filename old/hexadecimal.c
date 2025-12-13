/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:38:05 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/03 10:28:40 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

static void	print_rec(unsigned int nbr, const char *base, ssize_t *count);
static void	print_lrec(unsigned long nbr, const char *base, ssize_t *count);

int	ft_putunbr_hex(unsigned int nbr, t_bool uppercase)
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

	if (*count == -1)
		return ;
	if (nbr >= HEX_BASE_LEN)
		print_rec(nbr / HEX_BASE_LEN, base, count);
	if (*count == -1)
		return ;
	i = nbr % HEX_BASE_LEN;
	c = base[i];
	written = write(1, &c, 1);
	if (written < 0)
		*count = -1;
	else
		*count += written;
}

int	ft_putulnbr_hex(unsigned long nbr)
{
	ssize_t		count;
	const char	*base;

	count = write(1, "0x", 2);
	if (count < 0)
		return (-1);
	base = HEX_LOW_BASE;
	print_lrec(nbr, base, &count);
	return ((int) count);
}

static void	print_lrec(unsigned long nbr, const char *base, ssize_t *count)
{
	int		i;
	char	c;
	ssize_t	written;

	if (*count == -1)
		return ;
	if (nbr >= HEX_BASE_LEN)
		print_lrec(nbr / HEX_BASE_LEN, base, count);
	if (*count == -1)
		return ;
	i = nbr % HEX_BASE_LEN;
	c = base[i];
	written = write(1, &c, 1);
	if (written < 0)
		*count = -1;
	else
		*count += written;
}
