#include "test.h"

static void handle_child_status(pid_t pid)
{
	int	status;
	int	sig;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		fprintf(stderr, "💥 Test crashed: signal %d (%s)\n", sig, strsignal(sig));
		perror("Crash");
		g_failed++;
	}
	else if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == TRUE)
			g_passed++;
		else
			g_failed++;
	}
}

void	run_test_long(const char *format, long arg)
{
	pid_t		pid;
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[FORMATTED_INPUT_SIZE];
	t_bool		return_value;

    g_total++;
	pid = fork();
	if (pid < 0)
	{
		g_failed++;
		return (perror("Fork failed"));
	}
	if (pid == 0)
	{
		alarm(TIMEOUT);
		redirect_start(&fake_stdout);

		test.printf.return_value = printf(format, arg);
		redirect_read(&fake_stdout, test.printf.output);
		redirect_clear(&fake_stdout);

		test.ft_printf.return_value = ft_printf(format, arg);
		redirect_read(&fake_stdout, test.ft_printf.output);
		redirect_clear(&fake_stdout);

		redirect_stop(&fake_stdout);

		snprintf(formatted_input, FORMATTED_INPUT_SIZE, "%ld", arg);
		return_value = TRUE;
		if (!expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input))
			return_value = FALSE;
		if (!expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input))
			return_value = FALSE;
		exit(return_value);
	}
	else
		handle_child_status(pid);
}

void	run_test_string(const char *format, const char *arg)
{
	pid_t		pid;
	t_test		test;
	t_redirect	fake_stdout;
	t_bool		return_value;

    g_total++;
	pid = fork();
	if (pid < 0)
	{
		g_failed++;
		return (perror("Fork failed"));
	}
	if (pid == 0)
	{
		alarm(TIMEOUT);
		redirect_start(&fake_stdout);

		test.printf.return_value = printf(format, arg);
		redirect_read(&fake_stdout, test.printf.output);
		redirect_clear(&fake_stdout);

		test.ft_printf.return_value = ft_printf(format, arg);
		redirect_read(&fake_stdout, test.ft_printf.output);
		redirect_clear(&fake_stdout);

		redirect_stop(&fake_stdout);

		return_value = TRUE;
		if (!expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, arg))
			return_value = FALSE;
		if (!expect_str_eq(test.ft_printf.output, test.printf.output, format, arg))
			return_value = FALSE;
		exit(return_value);
	}
	else
		handle_child_status(pid);
}

void	run_test_unsigned(const char *format, unsigned int arg)
{
	pid_t		pid;
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[FORMATTED_INPUT_SIZE];
	t_bool		return_value;

    g_total++;
	pid = fork();
	if (pid < 0)
	{
		g_failed++;
		return (perror("Fork failed"));
	}
	if (pid == 0)
	{
		alarm(TIMEOUT);
		redirect_start(&fake_stdout);

		test.printf.return_value = printf(format, arg);
		redirect_read(&fake_stdout, test.printf.output);
		redirect_clear(&fake_stdout);

		test.ft_printf.return_value = ft_printf(format, arg);
		redirect_read(&fake_stdout, test.ft_printf.output);
		redirect_clear(&fake_stdout);

		redirect_stop(&fake_stdout);

		snprintf(formatted_input, FORMATTED_INPUT_SIZE, "%u", arg);
		return_value = TRUE;
		if (!expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input))
			return_value = FALSE;
		if (!expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input))
			return_value = FALSE;
		exit(return_value);
	}
	else
		handle_child_status(pid);
}

void	run_test_pointer(const char *format, void *arg)
{
	pid_t		pid;
	t_test		test;
	t_redirect	fake_stdout;
	char		formatted_input[FORMATTED_INPUT_SIZE];
	t_bool		return_value;

    g_total++;
	pid = fork();
	if (pid < 0)
	{
		g_failed++;
		return (perror("Fork failed"));
	}
	if (pid == 0)
	{
		alarm(TIMEOUT);
		redirect_start(&fake_stdout);

		test.printf.return_value = printf(format, arg);
		redirect_read(&fake_stdout, test.printf.output);
		redirect_clear(&fake_stdout);

		test.ft_printf.return_value = ft_printf(format, arg);
		redirect_read(&fake_stdout, test.ft_printf.output);
		redirect_clear(&fake_stdout);

		redirect_stop(&fake_stdout);

		snprintf(formatted_input, FORMATTED_INPUT_SIZE, "%p", arg);
		return_value = TRUE;
		if (!expect_eq_int(test.ft_printf.return_value, test.printf.return_value, format, formatted_input))
			return_value = FALSE;
		if (!expect_str_eq(test.ft_printf.output, test.printf.output, format, formatted_input))
			return_value = FALSE;
		exit(return_value);
	}
	else
		handle_child_status(pid);
}
