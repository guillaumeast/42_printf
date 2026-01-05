/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_life_cycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:30:37 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/13 01:30:38 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

bool	buff_init(t_buff *b, size_t initial_cap)
{
	b->cap = 0;
	if (initial_cap > 0)
	{
		b->data = malloc(initial_cap);
		if (!b->data)
			return (false);
	}
	else
		b->data = NULL;
	b->cap = initial_cap;
	b->len = 0;
	return (true);
}

void	buff_free(t_buff *b)
{
	if (b->data)
		free(b->data);
	b->data = NULL;
}
