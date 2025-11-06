#include "tests.h"

void	run_test_long(const char *format, long arg)
{
	t_test		test;
	t_redirect	fake_stdout;

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	cr_expect_eq(
		test.printf.return_value,
		test.ft_printf.return_value,
		"Different %sreturn value%s\n├── %sft_printf(\"%s\", %ld) = %d%s\n└───── printf(\"%s\", %ld) = %d",
		YELLOW, NONE, RED, format, arg, test.ft_printf.return_value, NONE, format, arg, test.printf.return_value
	);

	cr_expect_str_eq(
		test.printf.output,
		test.ft_printf.output,
		"Different %soutput%s\n├── %sft_printf(\"%s\", %ld) => \"%.20s\"%s\n└───── printf(\"%s\", %ld) => \"%.20s\"",
		YELLOW, NONE, RED, format, arg, test.ft_printf.output, NONE, format, arg, test.printf.output
	);
}

void	run_test_string(const char *format, const char *arg)
{
	t_test		test;
	t_redirect	fake_stdout;

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	cr_expect_eq(
		test.printf.return_value,
		test.ft_printf.return_value,
		"Different %sreturn value%s\n├── %sft_printf(\"%s\", %s) = %d%s\n└───── printf(\"%s\", %s) = %d",
		YELLOW, NONE, RED, format, arg, test.ft_printf.return_value, NONE, format, arg, test.printf.return_value
	);

	cr_expect_str_eq(
		test.printf.output,
		test.ft_printf.output,
		"Different %soutput%s\n├── %sft_printf(\"%s\", %s) => \"%.20s\"%s\n└───── printf(\"%s\", %s) => \"%.20s\"",
		YELLOW, NONE, RED, format, arg, test.ft_printf.output, NONE, format, arg, test.printf.output
	);
}

void	run_test_unsigned(const char *format, unsigned int arg)
{
	t_test		test;
	t_redirect	fake_stdout;

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	cr_expect_eq(
		test.printf.return_value,
		test.ft_printf.return_value,
		"Different %sreturn value%s\n├── %sft_printf(\"%s\", %u) = %d%s\n└───── printf(\"%s\", %u) = %d",
		YELLOW, NONE, RED, format, arg, test.ft_printf.return_value, NONE, format, arg, test.printf.return_value
	);

	cr_expect_str_eq(
		test.printf.output,
		test.ft_printf.output,
		"Different %soutput%s\n├── %sft_printf(\"%s\", %u) => \"%.20s\"%s\n└───── printf(\"%s\", %u) => \"%.20s\"",
		YELLOW, NONE, RED, format, arg, test.ft_printf.output, NONE, format, arg, test.printf.output
	);
}

void	run_test_pointer(const char *format, void *arg)
{
	t_test		test;
	t_redirect	fake_stdout;

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	cr_expect_eq(
		test.printf.return_value,
		test.ft_printf.return_value,
		"Different %sreturn value%s\n├── %sft_printf(\"%s\", %p) = %d%s\n└───── printf(\"%s\", %p) = %d",
		YELLOW, NONE, RED, format, arg, test.ft_printf.return_value, NONE, format, arg, test.printf.return_value
	);

	cr_expect_str_eq(
		test.printf.output,
		test.ft_printf.output,
		"Different %soutput%s\n├── %sft_printf(\"%s\", %p) => \"%.20s\"%s\n└───── printf(\"%s\", %p) => \"%.20s\"",
		YELLOW, NONE, RED, format, arg, test.ft_printf.output, NONE, format, arg, test.printf.output
	);
}
