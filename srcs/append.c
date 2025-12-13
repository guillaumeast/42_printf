/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:47:04 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/12 22:13:09 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

bool	append_char(t_buff *buff, char c)
{
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	return (buff_append(buff, tmp, 1));
}

bool	append_int(t_buff *buff, int nb)
{
	char	*tmp;
	bool	success;

	tmp = ft_itoa(nb);
	if (!tmp)
		return (false);
	success = buff_append(buff, tmp, -1);
	free(tmp);
	return (success);
}

bool	append_uint(t_buff *buff, unsigned int nb)
{
	char	*tmp;
	bool	success;

	tmp = ft_utoa(nb);
	if (!tmp)
		return (false);
	success = buff_append(buff, tmp, -1);
	free(tmp);
	return (success);
}

bool	append_hex(t_buff *buff, unsigned long nb, bool uppercase)
{
	char				*tmp;
	bool				success;
	static const char	upperbase[] = "0123456789ABCDEF";
	static const char	lowerbase[] = "0123456789abcdef";

	if (uppercase)
		tmp = ft_ultoa_base(nb, upperbase);
	else
		tmp = ft_ultoa_base(nb, lowerbase);
	if (!tmp)
		return (false);
	success = buff_append(buff, tmp, -1);
	free(tmp);
	return (success);
}

bool	append_ptr(t_buff *buff, unsigned long nb)
{
	if (nb == 0)
		return (buff_append(buff, "(nil)", 5));
	return (append_hex(buff, nb, false));
}
