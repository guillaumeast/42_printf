/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:20:49 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:36:21 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	target;

	last = NULL;
	target = (char) c;
	while (*s)
	{
		if (*s == target)
			last = (char *)s;
		s++;
	}
	if (target == '\0')
		last = (char *)s;
	return (last);
}
