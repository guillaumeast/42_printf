/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:30:40 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/13 01:30:41 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define DEFAULT_BUFF_CAP 128
#define BUFF_GROWTH 2

size_t	buff_get_required_cap(size_t current_cap, size_t target_len)
{
	size_t	new_cap;

	if (target_len == 0)
		return (current_cap);
	if (current_cap == 0)
		new_cap = DEFAULT_BUFF_CAP;
	else
		new_cap = current_cap;
	while (new_cap <= target_len)
		new_cap *= BUFF_GROWTH;
	return (new_cap);
}

bool	buff_prepend(t_buff *b, const char *str, long n)
{
	size_t	strlen;
	char	*new_data;
	size_t	new_cap;

	if (n < 0)
		strlen = ft_strlen(str);
	else
		strlen = (size_t)n;
	new_cap = buff_get_required_cap(b->cap, b->len + strlen);
	if (new_cap > b->cap)
	{
		new_data = malloc(new_cap);
		if (!new_data)
			return (false);
		b->cap = new_cap;
		ft_memcpy(new_data + strlen, b->data, b->len);
		free(b->data);
		b->data = new_data;
	}
	else
		ft_memmove(b->data + strlen, b->data, b->len);
	ft_memcpy(b->data, str, strlen);
	b->len = b->len + strlen;
	return (true);
}

bool	buff_insert(t_buff *b, size_t index, const char *str, long n)
{
	size_t	strlen;
	char	*new_data;
	size_t	new_cap;

	if (n < 0)
		strlen = ft_strlen(str);
	else
		strlen = (size_t)n;
	new_cap = buff_get_required_cap(b->cap, b->len + strlen);
	if (new_cap > b->cap)
	{
		new_data = malloc(new_cap);
		if (!new_data)
			return (false);
		b->cap = new_cap;
		ft_memcpy(new_data, b->data, index);
		ft_memcpy(new_data + index + strlen, b->data + index, b->len - index);
		free(b->data);
		b->data = new_data;
	}
	else
		ft_memmove(b->data + index + strlen, b->data + index, b->len - index);
	ft_memcpy(b->data + index, str, strlen);
	b->len = b->len + strlen;
	return (true);
}

bool	buff_append(t_buff *b, const char *str, long n)
{
	size_t	strlen;
	size_t	new_cap;

	if (n < 0)
		strlen = ft_strlen(str);
	else
		strlen = (size_t)n;
	new_cap = buff_get_required_cap(b->cap, b->len + strlen);
	if (new_cap > b->cap)
	{
		if (!ft_realloc(&b->data, b->cap, new_cap))
			return (false);
		b->cap = new_cap;
	}
	ft_memcpy(b->data + b->len, str, strlen);
	b->len = b->len + strlen;
	return (true);
}
