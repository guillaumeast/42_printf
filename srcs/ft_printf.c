/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:25:52 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/13 01:47:29 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "append.h"
#include "rules.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 512

static bool	parse(t_buff *buff, const char *fstring, va_list *args);
static bool	append(t_buff *buff, t_rules *rules, va_list *args);
static bool	append_str(t_buff *buff, const char *str);

int	ft_printf(const char *fstring, ...)
{
	t_buff	buff;
	va_list	args;
	bool	success;
	int		written;

	if (!buff_init(&buff, BUFF_SIZE))
		return (-1);
	va_start(args, fstring);
	success = parse(&buff, fstring, &args);
	va_end(args);
	written = (int)write(1, buff.data, buff.len);
	buff_free(&buff);
	if (!success)
		return (-1);
	return (written);
}

static bool	parse(t_buff *buff, const char *fstring, va_list *args)
{
	const char	*next_conversion;
	t_rules		rules;

	next_conversion = ft_strchr(fstring, '%');
	while (next_conversion)
	{
		if (!buff_append(buff, fstring, next_conversion - fstring))
			return (false);
		fstring = next_conversion + 1;
		rules_parse(&rules, &fstring);
		if (rules.conversion == '%')
		{
			if (!buff_append(buff, "%", 1))
				return (false);
		}
		else if (!append(buff, &rules, args))
			return (false);
		next_conversion = ft_strchr(fstring, '%');
	}
	return (buff_append(buff, fstring, -1));
}

static bool	append(t_buff *buff, t_rules *rules, va_list *args)
{
	t_buff	tmp_buff;
	bool	success;

	buff_init(&tmp_buff, 0);
	success = false;
	if (rules->conversion == 'c')
		success = append_char(&tmp_buff, va_arg(*args, int));
	else if (rules->conversion == 's')
		success = append_str(&tmp_buff, va_arg(*args, char *));
	else if (rules->conversion == 'd' || rules->conversion == 'i')
		success = append_int(&tmp_buff, va_arg(*args, int));
	else if (rules->conversion == 'u')
		success = append_uint(&tmp_buff, va_arg(*args, unsigned int));
	else if (rules->conversion == 'x')
		success = append_hex(&tmp_buff, va_arg(*args, unsigned int), false);
	else if (rules->conversion == 'X')
		success = append_hex(&tmp_buff, va_arg(*args, unsigned int), true);
	else if (rules->conversion == 'p')
		success = append_ptr(&tmp_buff, (unsigned long)va_arg(*args, void *));
	if (success)
		success = rules_apply(&tmp_buff, rules);
	if (success)
		success = buff_append(buff, tmp_buff.data, (long)tmp_buff.len);
	buff_free(&tmp_buff);
	return (success);
}

static bool	append_str(t_buff *buff, const char *str)
{
	if (!str)
		return (buff_append(buff, "(null)", 6));
	else
		return (buff_append(buff, str, -1));
}
