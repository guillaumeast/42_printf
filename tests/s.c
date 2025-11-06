#include "tests.h"

TestSuite(s, .timeout = 1);

Test(s, basic_strings)
{
	run_test_string("%s", "Hello");
	run_test_string("%s", "world");
	run_test_string("%s", "");
	run_test_string("%s", " ");
	run_test_string("%s", "42");
	run_test_string("%s", "Hello World");
}

Test(s, special_characters)
{
	run_test_string("%s", "\tTab\tSeparated");
	run_test_string("%s", "\nNew\nLine");
	run_test_string("%s", "\rCarriage\rReturn");
	run_test_string("%s", "Mix: \t\n\r");
	run_test_string("%s", "abc\0def");
}

Test(s, null_pointer)
{
	run_test_string("%s", NULL);
}
