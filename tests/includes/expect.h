#ifndef ASSERTS_H
# define ASSERTS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "colors.h"

void expect_init(void);
void expect_eq_int(int got, int expected, const char *input_format, const char *input_value);
void expect_str_eq(const char *got, const char *expected, const char *input_format, const char *input_value);
void print_results(void);

#endif
