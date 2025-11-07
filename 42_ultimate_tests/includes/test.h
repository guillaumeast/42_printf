#ifndef TESTS_H
# define TESTS_H

# include <stdio.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libftprintf.h"
# include "colors.h"
# include "redirect.h"
# include "expect.h"
# include "units.h"

# define FORMATTED_INPUT_SIZE 64
# define TIMEOUT 1

extern int g_passed;
extern int g_failed;
extern int g_total;

typedef int t_bool;
# define TRUE 1
# define FALSE 0

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
