#include "libftprintf.h"

static t_bool  dispatch_format(char c, va_list *args);

int ft_printf(const char *fstring, ...)
{
    va_list args;
	int		count;
    size_t  i;

    va_start(args, fstring);
	count = 0;
    i = 0;
    while (fstring[i])
    {
        if (fstring[i] == '%')
		{
            if (!dispatch_format(fstring[++i], &args))
				break;
		}
		else
        	write(1, &(fstring[i]), 1);
		count++;
        i++;
    }
    va_end(args);
	return (count);
}

static t_bool  dispatch_format(char c, va_list *args)
{
	// TODO: handle incorrect couple format-value ?
    if (c == 'c')	// TODO: cast to unsigned char inside ft_putchar_fd()
		ft_putchar_fd((unsigned char) va_arg(*args, int), 1);
    else if (c == 's')
		ft_putstr_fd((char *) va_arg(*args, char *), 1);
    else if (c == 'd' || c == 'i')
        ft_putnbr_fd((int) va_arg(*args, int), 1);
    else if (c == 'u')
		ft_putnbr_fd((unsigned int) va_arg(*args, int), 1); // TODO: add ft_putnbr_unsigned_fd()
    // else if (c == 'x')
	// 	ft_putnbr_base((unsigned int) va_arg(*args, int), "0123456789abcdef"); // TODO: add ft_putnbr_unsigned_base_fd()
    // else if (c == 'X')
	// 	ft_putnbr_base((unsigned int) va_arg(*args, int), "0123456789ABCDEF"); // TODO: add ft_putnbr_unsigned_base_fd()
	// else if (c == 'p')
	// 	ft_putnbr_base((unsigned int) va_arg(*args, void *), "0123456789abcdef"); // TODO: add ft_putnbr_unsigned_base_fd()
    else if (c == '%')
        write(1, "%", 1);
	else
		return (FALSE);
	return (TRUE);
}
