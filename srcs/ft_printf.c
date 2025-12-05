/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:25:52 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/05 21:46:15 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/*----- TODO: move into libft (START) -----*/
#define BUFF_SIZE 128
#define BUFF_GROWTH_RATIO 2

typedef struct s_buff
{
	char	*data;
	size_t	cap;
	size_t	len;
}	t_buff;

bool	buff_init(t_buff *buff)
{
	buff->data = malloc(BUFF_SIZE);
	if (!buff)
		return (false);
	buff->data[0] = '\0';
	buff->cap = BUFF_SIZE;
	buff->len = 0;
	return (true);
}

bool	buff_grow(t_buff *buff)
{
	size_t	new_cap;

	new_cap = buff->cap * BUFF_GROWTH_RATIO;
	if (!ft_realloc(buff->data, new_cap))
		return (false);
	buff->cap = new_cap;
	return (true);
}

bool	buff_append(t_buff *buff, const char *str, long n)
{
	size_t	strlen;
	size_t	i;

	if (!buff || !str)
		return (false);
	strlen = ft_strnlen(str, n);
	if (buff->len + strlen >= buff->cap && !buff_grow(buff))
		return (false);
	i = 0;
	while (i < strlen && (n == -1 || i < (size_t)n))
	{
		buff->data[buff->len + i] = str[i];
		i++;
	}
	buff->len = buff->len + i - 1;
	return (true);
}

void	buff_free(t_buff *buff)
{
	if (buff->data)
		free(buff->data);
	buff->data = NULL;
}

char	*ft_strchr(const char *str);	// TODO

/*----- TODO: move into libft (END) -----*/

static int	flush(t_buff *buff, va_list *args, bool is_error);

char	*convert(char **fstring_ptr, va_list *args);	// TODO

int	ft_printf(const char *fstring, ...)
{
	t_buff	buff;
	char	*ptr;
	char	*next_conversion;
	va_list	args;

	if (!buff_init(&buff))
		return (-1);
	ptr = fstring;
	va_start(args, fstring);
	while ((next_conversion = ft_strchr(ptr)))
	{
		if (!buff_append(&buff, ptr, next_conversion - ptr))
			return (flush(&buff, &args, true));
		ptr = next_conversion;
		if (!buff_append(&buff, convert(&ptr, &args), -1))
			return (flush(&buff, &args, true));
	}
	buff_append(&buff, ptr, -1);
	return (flush(&buff, &args, false));
}

static int	flush(t_buff *buff, va_list *args, bool is_error)
{
	int	written;
	
	va_end(*args);
	written = (int)write(1, buff->data, buff->len);
	buff_free(buff);
	if (is_error)
		return (-1);
	return (written);
}
