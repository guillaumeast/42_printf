#include "tests.h"

TestSuite(X, .timeout = 1);

Test(X, basic_values)
{
	run_test_unsigned("%X", 0);
	run_test_unsigned("%X", 42);
}

Test(X, padding_and_spacing)
{
	run_test_unsigned("-%X-", 0);
	run_test_unsigned(" %X ", 42);
}

Test(X, limits)
{
	run_test_long("%X", INT_MIN);
	run_test_unsigned("%X", INT_MAX);
	run_test_unsigned("%X", UINT_MAX);
}

Test(X, negative_values)
{
	run_test_long("%X", -1);
	run_test_long("%X", -42);
}
