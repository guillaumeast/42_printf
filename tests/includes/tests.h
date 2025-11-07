#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <limits.h>
# include "libftprintf.h"
# include "redirect.h"
# include "colors.h"

# define TO_STRING_BUFF_SIZE 64
# define to_string(x, buf, size) \
    _Generic((x), \
        int: snprintf(buf, size, "%d", x), \
        long: snprintf(buf, size, "%ld", x), \
        unsigned int: snprintf(buf, size, "%u", x), \
        double: snprintf(buf, size, "%f", x), \
        default: snprintf(buf, size, "%s", "(unsupported)") \
    )

typedef struct s_result
{
	char	output[OUT_MAX];
	int		return_value;
}	t_result;

typedef struct s_test
{
	t_result	printf;
	t_result	ft_printf;
}	t_test;

void	run_test_long(const char *format, long arg);
void	run_test_string(const char *format, const char *arg);
void	run_test_unsigned(const char *format, unsigned int arg);
void	run_test_pointer(const char *format, void *arg);

#endif
