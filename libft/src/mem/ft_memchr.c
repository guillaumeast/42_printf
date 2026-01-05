/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:19:57 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:31:33 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		target;
	const unsigned char	*str;
	size_t				i;

	target = (unsigned char) c;
	str = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str[i] == target)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
