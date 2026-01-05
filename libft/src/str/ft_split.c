/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:20:20 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/06 23:34:29 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char sep);
static char		*get_word(char const *s, char sep);
static char		**free_all(char **tab);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i] = NULL;
			res[i] = get_word(s, c);
			if (!res[i++])
				return (free_all(res));
			while (*s && *s != c)
				s++;
			continue ;
		}
		s++;
	}
	res[i] = NULL;
	return (res);
}

static size_t	count_words(char const *s, char sep)
{
	size_t	count;
	char	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!in_word && *s != sep)
		{
			in_word = 1;
			count++;
		}
		else if (in_word && *s == sep)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char sep)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != sep)
		len++;
	return (ft_substr(s, 0, len));
}

static char	**free_all(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}
