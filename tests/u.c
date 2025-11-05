#include "tests.h"

Test(u, basic_values)
{
	run_test("%u", 0);
	run_test("%u", 1);
	run_test("%u", 42);
}

Test(u, int_boundaries)
{
	run_test("%u", -1);
	run_test("%u", -42);
	run_test("%u", INT_MAX);
	run_test("%u", INT_MIN);
}

Test(u, unsigned_limits)
{
	run_test("%u", UINT_MAX);
	run_test("%u", UINT_MAX - 1);
	run_test("%u", UINT_MAX / 2);
}
