#include "libftprintf.h"

void ft_printf(const char *fstring, ...)
{
    va_list args;
    size_t  i;
    size_t  count;
    char    c;

    i = 0;
    count = 0;
    va_start(args, fstring);
    while (fstring[i])
    {
        if (fstring[i] == '%' && fstring[i + 1] == 'd')
        {
            c = va_arg(args, int) + '0';
            write(1, &c, 1);
            i += 2;
            continue;
        }
        c = fstring[i];
        write(1, &c, 1);
        i++;
    }
    va_end(args);
}

t_bool  is_format(char c)
{
    if (c == 'c')
    else if (c == 's')
    else if (c == 'p')
    else if (c == 'd')
    else if (c == 'i')
        ft_putnbr()
    else if (c == 'u')
    else if (c == 'x')
    else if (c == 'X')
    else if (c == '%')
        write(1, "%", 1);
    else
    {
        write(2, "Unsupported format: ", 20);
        write(2, &c, 1);
        write(2, "\n", 1);
    }
}
