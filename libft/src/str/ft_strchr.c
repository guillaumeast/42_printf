/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:20:23 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:34:46 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	target;

	target = (char) c;
	while (*s)
	{
		if (*s == target)
			return ((char *) s);
		s++;
	}
	if (target == '\0')
		return ((char *) s);
	return (NULL);
}
