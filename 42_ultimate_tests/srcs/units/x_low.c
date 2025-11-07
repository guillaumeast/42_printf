#include "test.h"

void	test_x_low(void)
{
	printf("👉 Testing '%%x' with basic values\n");
	run_test_unsigned("%x", 0);
	run_test_unsigned("%x", 42);

	printf("👉 Testing '%%x' with padding and spacing\n");
	run_test_unsigned("-%x-", 0);
	run_test_unsigned(" %x ", 42);

	printf("👉 Testing '%%x' with int limits\n");
	run_test_long("%x", INT_MIN);
	run_test_unsigned("%x", INT_MAX);

	printf("👉 Testing '%%x' with unsigned int limits\n");
	run_test_unsigned("%x", UINT_MAX);

	printf("👉 Testing '%%x' with negative values\n");
	run_test_long("%x", -1);
	run_test_long("%x", -42);

	printf("\n");
}
