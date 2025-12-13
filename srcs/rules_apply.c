#include "libft.h"
#include "rules.h"
#include <stdlib.h>

static bool	apply_precision(t_buff *buff, t_rules *rules);
static bool	apply_plus_space(t_buff *buff, t_rules *r);
static bool	apply_hex_prefix(t_buff *buff, t_rules *rules);
static bool	apply_width(t_buff *buff, t_rules *rules);

bool	rules_apply(t_buff *buff, t_rules *rules)
{
	if (!apply_precision(buff, rules))
		return (false);
	if (!apply_plus_space(buff, rules))
		return (false);
	if (!apply_hex_prefix(buff, rules))
		return (false);
	if (!apply_width(buff, rules))
		return (false);
	return (true);
}

static bool	apply_precision(t_buff *buff, t_rules *rules)
{
	long	zeros_len;
	char	*zeros;
	bool	success;

	if (rules->precision == -1)
		return (true);
	else if (rules->conversion == 's' && buff->len > (size_t)rules->precision)
		buff->len = (size_t)rules->precision;
	else if (rules->precision == 0 && buff->len == 1 && buff->data[0] == '0')
		buff->len = 0;
	else if (buff->len < (size_t)rules->precision)
	{
		zeros_len = (long)((size_t)rules->precision - buff->len);
		zeros = malloc((size_t)zeros_len);
		if (!zeros)
			return (false);
		ft_memset(zeros, '0', (size_t)zeros_len);
		success = buff_insert(buff, (buff->data[0] == '-'), zeros, zeros_len);
		free(zeros);
		return (success);
	}
	return (true);
}

static bool	apply_plus_space(t_buff *buff, t_rules *r)
{
	char	sign;

	sign = buff->data[0];
	if ((!r->plus && !r->space) || sign == '-')
		return (true);
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
	char	conv;
	char	prefix[2];

	conv = rules->conversion;
	if (!rules->hex_prefix)
		return (true);
	if (buff->len == 0 || (buff->len == 1 && buff->data[0] == '0'))
		return (true);
	prefix[0] = '0';
	if (conv == 'X')
		prefix[1] = 'X';
	else
		prefix[1] = 'x';
	return (buff_prepend(buff, prefix, 2));
}

static bool	apply_width(t_buff *b, t_rules *rules)
{
	char	*padding;
	size_t	padding_len;
	bool	success;

	if (!rules->width_enabled || b->len >= (size_t)rules->width)
		return (true);
	padding_len = (size_t)rules->width - b->len;
	padding = malloc(padding_len);
	if (!padding)
		return (false);
	if (rules->zero_padding)
		ft_memset(padding, '0', padding_len);
	else
		ft_memset(padding, ' ', padding_len);
	if (rules->right_padding)
		success = buff_append(b, padding, (long)padding_len);
	else if (rules->zero_padding && b->data[0] == '-')
		success = buff_insert(b, 1, padding, (long)padding_len);
	else if (rules->zero_padding && b->data[0] == '0'
		&& (b->data[1] == 'x' || b->data[1] == 'X'))
		success = buff_insert(b, 2, padding, (long)padding_len);
	else
		success = buff_prepend(b, padding, (long)padding_len);
	free(padding);
	return (success);
}
