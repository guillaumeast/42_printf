#include "test.h"

void	test_i(void)
{
	printf("👉 Testing '%%i' with basic values\n");
	run_test_long("%i", 0);
	run_test_long("%i", 1);

	printf("👉 Testing '%%i' with signed values\n");
	run_test_long("%i", +0);
	run_test_long("%i", -0);
	run_test_long("%i", +1);
	run_test_long("%i", -1);

	printf("👉 Testing '%%i' with int limits\n");
	run_test_long("%i", INT_MAX);
	run_test_long("%i", INT_MIN);

	printf("\n");
}
