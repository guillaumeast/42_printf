#include "tests.h"

TestSuite(c, .timeout = 1);

Test(c, printable_chars)
{
	run_test_long("%c", 33);
	run_test_long("%c", 'A');
	run_test_long("%c", 'z');
	run_test_long("%c", 126);
}

Test(c, non_printable_chars)
{
	run_test_long("%c", 0);   // NUL
	run_test_long("%c", 7);   // BEL
	run_test_long("%c", 9);   // TAB
	run_test_long("%c", 10);  // LF
	run_test_long("%c", 13);  // CR
	run_test_long("%c", 31);  // Unit separator
	run_test_long("%c", 127); // DEL
}

Test(c, signed_values)
{
	run_test_long("%c", -1);
	run_test_long("%c", -42);
	run_test_long("%c", -128); // min for signed char
}

Test(c, unsigned_overflow)
{
	// Values beyond 255 are wrapped modulo 256
	run_test_long("%c", 255);
	run_test_long("%c", 256);
	run_test_long("%c", 257);
	run_test_long("%c", 512);
	run_test_long("%c", 1024);
}

Test(c, limits)
{
	// Extremes of the int range (they’ll be truncated to a single byte)
	run_test_long("%c", INT_MAX);
	run_test_long("%c", INT_MIN);
}
