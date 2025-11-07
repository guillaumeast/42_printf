#include "test.h"

int g_passed = 0;
int g_failed = 0;
int g_total  = 0;

int	main(void)
{
	expect_init();

	test_basic();
	test_c();
	test_d();
	test_i();
	test_p();
	test_s();
	test_u();
	test_x_low();
	test_x_upp();

	print_results();
}
