/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 01:39:42 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/13 03:10:11 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rules.h"
#include <stdlib.h>

static bool	apply_precision(t_buff *buff, t_rules *rules);
static bool	apply_plus_space(t_buff *buff, t_rules *r);
static bool	apply_hex_prefix(t_buff *buff, t_rules *rules);
static bool	apply_width(t_buff *buff, t_rules *rules);

bool	rules_apply(t_buff *buff, t_rules *rules)
{
	if (buff->len == 1 && buff->data[0] == '0')
		rules->is_zero = true;
	if (rules->precision != -1 && !apply_precision(buff, rules))
		return (false);
	if ((rules->plus || rules->space) && !apply_plus_space(buff, rules))
		return (false);
	if (rules->hex_prefix && !apply_hex_prefix(buff, rules))
		return (false);
	if (rules->width_enabled && !apply_width(buff, rules))
		return (false);
	return (true);
}

static bool	apply_precision(t_buff *buff, t_rules *rules)
{
	size_t	len_without_sign;
	long	zeros_len;
	char	*zeros;
	bool	success;

	if (rules->conversion == 's')
	{
		if (buff->len > (size_t)rules->precision)
			buff->len = (size_t)rules->precision;
		return (true);
	}
	len_without_sign = buff->len - (buff->data[0] == '-');
	if (rules->precision == 0 && buff->len == 1 && buff->data[0] == '0')
		buff->len = 0;
	else if (len_without_sign < (size_t)rules->precision)
	{
		zeros_len = (long)((size_t)rules->precision - len_without_sign);
		zeros = malloc((size_t)zeros_len);
		if (!zeros)
			return (false);
		ft_memset(zeros, '0', (size_t)zeros_len);
		success = buff_insert(buff, (buff->data[0] == '-'), zeros, zeros_len);
		return (free(zeros), success);
	}
	return (true);
}

static bool	apply_plus_space(t_buff *buff, t_rules *r)
{
	char	sign;

	if (buff->data[0] == '-')
		return (true);
	sign = buff->data[0];
	if (r->plus)
	{
		sign = '+';
		return (buff_prepend(buff, &sign, 1));
	}
	else if (r->space)
	{
		sign = ' ';
		return (buff_prepend(buff, &sign, 1));
	}
	return (true);
}

static bool	apply_hex_prefix(t_buff *buff, t_rules *rules)
{
	char	prefix[2];

	if (buff->data[0] == '(' || rules->is_zero)
		return (true);
	if (buff->len == 0 || (buff->len == 1 && buff->data[0] == '0'))
		return (true);
	prefix[0] = '0';
	if (rules->conversion == 'X')
		prefix[1] = 'X';
	else
		prefix[1] = 'x';
	return (buff_prepend(buff, prefix, 2));
}

static bool	apply_width(t_buff *b, t_rules *r)
{
	char	*padding;
	size_t	padding_len;
	bool	success;

	if (b->len >= (size_t)r->width)
		return (true);
	padding_len = (size_t)r->width - b->len;
	padding = malloc(padding_len);
	if (!padding)
		return (false);
	if (r->zero_padding)
		ft_memset(padding, '0', padding_len);
	else
		ft_memset(padding, ' ', padding_len);
	if (r->right_padding)
		success = buff_append(b, padding, (long)padding_len);
	else if (r->zero_padding && (b->data[0] == '-' || r->plus || r->space))
		success = buff_insert(b, 1, padding, (long)padding_len);
	else if (r->zero_padding && b->data[0] == '0'
		&& (b->data[1] == 'x' || b->data[1] == 'X'))
		success = buff_insert(b, 2, padding, (long)padding_len);
	else
		success = buff_prepend(b, padding, (long)padding_len);
	free(padding);
	return (success);
}
