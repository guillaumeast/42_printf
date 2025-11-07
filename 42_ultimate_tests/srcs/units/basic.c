#include "test.h"

void	test_basic(void)
{
	printf("👉 Testing '%%%%'\n");
	run_test_long("%%", 0);
	run_test_long(" %% ", 0);
	run_test_long("-%%-", 0);

	printf("👉 Testing '%%_' (invalid format)\n");
	run_test_long("12%_45", 0);

	printf("\n");
}
