#include "tests.h"
#include "expect.h"

void	run_test_long(const char *format, long arg)
{
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[TO_STRING_BUFF_SIZE];

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	to_string(arg, formatted_input, TO_STRING_BUFF_SIZE);
	expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input);
	expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input);
}

void	run_test_string(const char *format, const char *arg)
{
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[TO_STRING_BUFF_SIZE];

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	to_string(arg, formatted_input, TO_STRING_BUFF_SIZE);
	expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input);
	expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input);
}

void	run_test_unsigned(const char *format, unsigned int arg)
{
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[TO_STRING_BUFF_SIZE];

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	to_string(arg, formatted_input, TO_STRING_BUFF_SIZE);
	expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input);
	expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input);
}

void	run_test_pointer(const char *format, void *arg)
{
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[TO_STRING_BUFF_SIZE];

	redirect_start(&fake_stdout);

	test.printf.return_value = printf(format, arg);
	redirect_read(&fake_stdout, test.printf.output);
	redirect_clear(&fake_stdout);

	test.ft_printf.return_value = ft_printf(format, arg);
	redirect_read(&fake_stdout, test.ft_printf.output);
	redirect_clear(&fake_stdout);

	redirect_stop(&fake_stdout);

	to_string(arg, formatted_input, TO_STRING_BUFF_SIZE);
	expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input);
	expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input);
}
