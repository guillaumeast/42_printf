#include "tests.h"

TestSuite(x, .timeout = 1);

Test(x, basic_values)
{
	run_test_unsigned("%x", 0);
	run_test_unsigned("%x", 42);
}

Test(x, padding_and_spacing)
{
	run_test_unsigned("-%x-", 0);
	run_test_unsigned(" %x ", 42);
}

Test(x, limits)
{
	run_test_long("%x", INT_MIN);
	run_test_unsigned("%x", INT_MAX);
	run_test_unsigned("%x", UINT_MAX);
}

Test(x, negative_values)
{
	run_test_long("%x", -1);
	run_test_long("%x", -42);
}
