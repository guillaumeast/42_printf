#include "tests.h"

Test(c, printable_chars)
{
	run_test("%c", 33);
	run_test("%c", 'A');
	run_test("%c", 'z');
	run_test("%c", 126);
}

Test(c, non_printable_chars)
{
	run_test("%c", 0);   // NUL
	run_test("%c", 7);   // BEL
	run_test("%c", 9);   // TAB
	run_test("%c", 10);  // LF
	run_test("%c", 13);  // CR
	run_test("%c", 31);  // Unit separator
	run_test("%c", 127); // DEL
}

Test(c, signed_values)
{
	run_test("%c", -1);
	run_test("%c", -42);
	run_test("%c", -128); // min for signed char
}

Test(c, unsigned_overflow)
{
	// Values beyond 255 are wrapped modulo 256
	run_test("%c", 255);
	run_test("%c", 256);
	run_test("%c", 257);
	run_test("%c", 512);
	run_test("%c", 1024);
}

Test(c, int_extremes)
{
	// Extremes of the int range (they’ll be truncated to a single byte)
	run_test("%c", INT_MAX);
	run_test("%c", INT_MIN);
}
