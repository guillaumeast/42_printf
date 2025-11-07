#include "test.h"

void	test_s(void)
{
	printf("👉 Testing '%%s' with basic values\n");
	run_test_string("%s", "Hello");
	run_test_string("%s", "world");
	run_test_string("%s", "");
	run_test_string("%s", " ");
	run_test_string("%s", "42");
	run_test_string("%s", "Hello World");

	printf("👉 Testing '%%s' with basic special characters\n");
	run_test_string("%s", "\tTab\tSeparated");
	run_test_string("%s", "\nNew\nLine");
	run_test_string("%s", "\rCarriage\rReturn");
	run_test_string("%s", "Mix: \t\n\r");
	run_test_string("%s", "abc\0def");

	printf("👉 Testing '%%s' with NULL pointer\n");
	run_test_string("%s", NULL);

	printf("\n");
}
