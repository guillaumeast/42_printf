#include "tests.h"

TestSuite(p, .timeout = 1);

Test(p, null_pointer)
{
	run_test_pointer("%p", NULL);
}

Test(p, stack_addresses)
{
	int a = 42;
	int b = -1;

	run_test_pointer("%p", &a);
	run_test_pointer("%p", &b);
	run_test_pointer("-%p-", &a);
	run_test_pointer(" %p ", &b);
}

Test(p, heap_addresses)
{
	void *ptr1 = malloc(1);
	void *ptr2 = malloc(1000);

	run_test_pointer("%p", ptr1);
	run_test_pointer("%p", ptr2);
	run_test_pointer("-%p-", ptr1);
	run_test_pointer(" %p ", ptr2);

	free(ptr1);
	free(ptr2);
}

Test(p, limits)
{
	run_test_pointer("%p", (void *)INT_MIN);
	run_test_pointer("%p", (void *)INT_MAX);
	run_test_pointer("%p", (void *)UINT_MAX);
	run_test_pointer("%p", (void *)LONG_MIN);
	run_test_pointer("%p", (void *)LONG_MAX);
}
