/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:19:29 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/12 19:30:01 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_len(long n);
static void		populate(long n, char *str, size_t i);

char	*ft_ltoa(long n)
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

static size_t	get_len(long n)
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

static void	populate(long n, char *str, size_t i)
{
	int	mod;

	if (n >= 10 || n <= -10)
		populate(n / 10, str, i - 1);
	mod = n % 10;
	if (mod < 0)
		mod *= -1;
	str[i] = (char)mod + '0';
}
