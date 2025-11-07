#include "test.h"

void	test_x_upp(void)
{
	printf("👉 Testing '%%X' with basic values\n");
	run_test_unsigned("%X", 0);
	run_test_unsigned("%X", 42);

	printf("👉 Testing '%%X' with padding and spacing\n");
	run_test_unsigned("-%X-", 0);
	run_test_unsigned(" %X ", 42);

	printf("👉 Testing '%%X' with int limits\n");
	run_test_long("%X", INT_MIN);
	run_test_unsigned("%X", INT_MAX);

	printf("👉 Testing '%%X' with unsigned int limits\n");
	run_test_unsigned("%X", UINT_MAX);

	printf("👉 Testing '%%X' with negative values\n");
	run_test_long("%X", -1);
	run_test_long("%X", -42);

	printf("\n");
}
