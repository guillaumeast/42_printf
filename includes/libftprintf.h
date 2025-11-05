#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "libft.h"

typedef char t_bool;
# define TRUE 1
# define FALSE 0

int ft_printf(const char *fstring, ...);

#endif
