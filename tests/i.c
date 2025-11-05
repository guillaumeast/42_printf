#include "tests.h"

Test(i, basic_values)
{
	run_test("%i", 0);
	run_test("%i", 1);
}

Test(i, sign_behavior)
{
	run_test("%i", +0);
	run_test("%i", -0);
	run_test("%i", +1);
	run_test("%i", -1);
}

Test(i, int_limits)
{
	run_test("%i", INT_MAX);
	run_test("%i", INT_MIN);
}
