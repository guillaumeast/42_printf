#include "tests.h"

TestSuite(i, .timeout = 1);

Test(i, basic_values)
{
	run_test_long("%i", 0);
	run_test_long("%i", 1);
}

Test(i, sign_behavior)
{
	run_test_long("%i", +0);
	run_test_long("%i", -0);
	run_test_long("%i", +1);
	run_test_long("%i", -1);
}

Test(i, limits)
{
	run_test_long("%i", INT_MAX);
	run_test_long("%i", INT_MIN);
}
