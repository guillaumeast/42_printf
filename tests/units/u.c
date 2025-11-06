#include "tests.h"

TestSuite(u, .timeout = 1);

Test(u, basic_values)
{
	run_test_unsigned("%u", 0);
	run_test_unsigned("%u", 1);
	run_test_unsigned("%u", 42);
}

Test(u, limits)
{
	run_test_long("%u", -1);
	run_test_long("%u", -42);
	run_test_unsigned("%u", INT_MIN);
	run_test_unsigned("%u", INT_MAX);
	run_test_unsigned("%u", UINT_MAX);
}
