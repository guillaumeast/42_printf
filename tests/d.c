#include "tests.h"

Test(d, basic_values)
{
	run_test("%d", 0);
	run_test("%d", 1);
}

Test(d, sign_behavior)
{
	run_test("%d", +0);
	run_test("%d", -0);
	run_test("%d", +1);
	run_test("%d", -1);
}

Test(d, int_limits)
{
	run_test("%d", INT_MAX);
	run_test("%d", INT_MIN);
}
