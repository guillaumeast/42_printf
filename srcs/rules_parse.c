/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:45:32 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/13 03:05:52 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rules.h"

static void	parse_flags(t_rules *rules, const char **fstring);
static void	parse_width(t_rules *rules, const char **fstring);
static void	parse_precision(t_rules *rules, const char **fstring);
static void	normalize(t_rules *rules);

void	rules_parse(t_rules *rules, const char **fstring)
{
	const char	conversion_set[] = "csdiuxXp";

	rules->plus = false;
	rules->space = false;
	rules->hex_prefix = false;
	rules->zero_padding = false;
	rules->right_padding = false;
	rules->precision = -1;
	rules->width_enabled = false;
	rules->width = -1;
	rules->conversion = '\0';
	rules->is_zero = false;
	if (**fstring != '%')
	{
		parse_flags(rules, fstring);
		if (**fstring != '.' && !ft_isincharset(**fstring, conversion_set))
			parse_width(rules, fstring);
		if (**fstring == '.')
			parse_precision(rules, fstring);
	}
	rules->conversion = **fstring;
	normalize(rules);
	(*fstring)++;
}

static void	parse_flags(t_rules *rules, const char **fstring)
{
	const char	flag_set[] = "-0# +";
	char		c;

	while (ft_isincharset(**fstring, flag_set))
	{
		c = **fstring;
		if (c == '-')
			rules->right_padding = true;
		else if (c == '0')
			rules->zero_padding = true;
		else if (c == '#')
			rules->hex_prefix = true;
		else if (c == ' ')
			rules->space = true;
		else if (c == '+')
			rules->plus = true;
		(*fstring)++;
	}
}

static void	parse_width(t_rules *rules, const char **fstring)
{
	rules->width_enabled = true;
	rules->width = ft_atoi(*fstring);
	while (ft_isdigit(**fstring))
		(*fstring)++;
}

static void	parse_precision(t_rules *rules, const char **fstring)
{
	rules->zero_padding = false;
	(*fstring)++;
	rules->precision = ft_atoi(*fstring);
	while (ft_isdigit(**fstring))
		(*fstring)++;
}

static void	normalize(t_rules *rules)
{
	char	conv;

	conv = rules->conversion;
	if (conv != 'x' && conv != 'X' && conv != 'p')
		rules->hex_prefix = false;
	if (conv == 'p')
	{
		rules->hex_prefix = true;
		rules->precision = -1;
	}
	if (conv == 'c')
		rules->precision = -1;
	if (conv != 'd' && conv != 'i')
		rules->plus = false;
	if ((conv != 'd' && conv != 'i') || rules->plus)
		rules->space = false;
	if (rules->width_enabled && rules->width < 0)
	{
		rules->right_padding = true;
		rules->width = -rules->width;
	}
	if (rules->right_padding || rules->precision != -1)
		rules->zero_padding = false;
}
