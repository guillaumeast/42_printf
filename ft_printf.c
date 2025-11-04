#include "libftprintf.h"

static void  dispatch_format(char c, va_list *args);

void ft_printf(const char *fstring, ...)
{
    va_list args;
    size_t  i;

    va_start(args, fstring);
    i = 0;
    while (fstring[i])
    {
        if (fstring[i] == '%')
            dispatch_format(fstring[++i], &args);
		else
        	write(1, &(fstring[i]), 1);
        i++;
    }
    va_end(args);
}

static void  dispatch_format(char c, va_list *args)
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
	{
		write(2, "[Unsupported: '%", 17);
		write(2, &c, 1);
		write(2, "']", 2);
	}
}
