#ifndef TESTS_H
# define TESTS_H

# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <stdio.h>
# include <limits.h>

# include "libftprintf.h"
# include "redirect.h"

# define RED "\033[31m"
# define YELLOW "\033[33m"
# define NONE "\033[0m"

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
