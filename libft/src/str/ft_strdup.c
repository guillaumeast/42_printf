/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:20:26 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:35:03 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1)
{
	char	*res;

	res = malloc(ft_strlen(s1) + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	return (res);
}

static	void	ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
