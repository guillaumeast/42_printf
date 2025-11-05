#include "libftprintf.h"

static int  dispatch_format(char format, va_list *args);

int	ft_printf(const char *fstring, ...)
{
	va_list args;
	int		written;
	int		count;
	int		i;

	va_start(args, fstring);
	count = 0;
	i = -1;
	while (fstring[++i])
	{
		if (fstring[i] == '%')
		{
			written = dispatch_format(fstring[++i], &args);
			if (written < 0)
				break;
			count += (int) written;
		}
		else
		{
			write(1, &(fstring[i]), 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

static int	dispatch_format(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_hex(va_arg(*args, unsigned int), FALSE));
	else if (format == 'X')
		return (ft_putnbr_hex(va_arg(*args, unsigned int), TRUE));
	else if (format == 'p')
		return (ft_putnbr_hex(va_arg(*args, void *), TRUE));
	else if (format == '%')
		return ((int) write(1, "%", 1));
	else
		return (-1);
}

