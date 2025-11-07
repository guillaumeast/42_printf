#include "test.h"

void	test_c(void)
{
	printf("👉 Testing '%%c' with printable chars\n");
	run_test_long("%c", 33);
	run_test_long("%c", 'A');
	run_test_long("%c", 'z');
	run_test_long("%c", 126);

	printf("👉 Testing '%%c' with non-printable chars\n");
	run_test_long("%c", 0);   // NUL
	run_test_long("%c", 7);   // BEL
	run_test_long("%c", 9);   // TAB
	run_test_long("%c", 10);  // LF
	run_test_long("%c", 13);  // CR
	run_test_long("%c", 31);  // Unit separator
	run_test_long("%c", 127); // DEL

	printf("👉 Testing '%%c' with signed values\n");
	run_test_long("%c", -1);
	run_test_long("%c", -42);
	run_test_long("%c", -128); // min for signed char

	printf("👉 Testing '%%c' with unsigned overflow\n");
	// Values beyond 255 are wrapped modulo 256
	run_test_long("%c", 255);
	run_test_long("%c", 256);
	run_test_long("%c", 257);
	run_test_long("%c", 512);
	run_test_long("%c", 1024);

	printf("👉 Testing '%%c' with int limits\n");
	// Extremes of the int range (they’ll be truncated to a single byte)
	run_test_long("%c", INT_MAX);
	run_test_long("%c", INT_MIN);

	printf("\n");
}
