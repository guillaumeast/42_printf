#include "test.h"

void	test_u(void)
{
	printf("👉 Testing '%%u' with basic values\n");
	run_test_unsigned("%u", 0);
	run_test_unsigned("%u", 1);
	run_test_unsigned("%u", 42);

	printf("👉 Testing '%%u' with basic values\n");
	run_test_long("%u", -1);
	run_test_long("%u", -42);
	run_test_unsigned("%u", INT_MIN);
	run_test_unsigned("%u", INT_MAX);
	run_test_unsigned("%u", UINT_MAX);

	printf("\n");
}
