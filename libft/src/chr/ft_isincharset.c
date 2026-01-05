/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isincharset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:30:28 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/11 21:32:09 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_isincharset(char c, const char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (true);
		charset++;
	}
	return (false);
}
