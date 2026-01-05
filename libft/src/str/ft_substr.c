/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:20:55 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:36:54 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	min_len;
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	min_len = ft_strlen(s + start);
	if (min_len < len)
		res = malloc(min_len + 1);
	else
		res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
