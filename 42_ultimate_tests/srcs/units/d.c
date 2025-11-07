#include "test.h"

void	test_d(void)
{
	printf("👉 Testing '%%d' with basic values\n");
	run_test_long("%d", 0);
	run_test_long("%d", 1);

	printf("👉 Testing '%%d' with signed values\n");
	run_test_long("%d", +0);
	run_test_long("%d", -0);
	run_test_long("%d", +1);
	run_test_long("%d", -1);

	printf("👉 Testing '%%d' with int limits\n");
	run_test_long("%d", INT_MAX);
	run_test_long("%d", INT_MIN);

	printf("\n");
}
