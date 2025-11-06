#include "tests.h"

TestSuite(d, .timeout = 1);

Test(d, basic_values)
{
	run_test_long("%d", 0);
	run_test_long("%d", 1);
}

Test(d, sign_behavior)
{
	run_test_long("%d", +0);
	run_test_long("%d", -0);
	run_test_long("%d", +1);
	run_test_long("%d", -1);
}

Test(d, limits)
{
	run_test_long("%d", INT_MAX);
	run_test_long("%d", INT_MIN);
}
