#include "tests.h"

Test(basic, pourcent)
{
	run_test("%%", 0);
}

Test(basic, invalid)
{
	run_test("12%45", 0);
}
