#include "tests.h"

TestSuite(basic, .timeout = 1);

Test(basic, pourcent)
{
	run_test_long("%%", 0);
}

Test(basic, invalid)
{
	run_test_long("12%45", 0);
}
