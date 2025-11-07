#include "test.h"

void expect_init(void)
{
    g_passed = g_failed = g_total = 0;
    printf("\n");
}

t_bool expect_eq_int(int got, int expected, const char *input_format, const char *input_value)
{
    if (got == expected)
        return (TRUE);
    else
    {
        printf("------------------------------\n");
        printf("Different %sreturn value%s\n", YELLOW, NONE);
        printf("├── %sft_printf(\"%s\", %s) = %d%s\n", RED, input_format, input_value, got, NONE);
        printf("└───── printf(\"%s\", %s) = %d\n", input_format, input_value, expected);
        printf("------------------------------\n");
        return (FALSE);
    }
}

t_bool expect_str_eq(const char *got, const char *expected, const char *input_format, const char *input_value)
{
    if (strcmp(got, expected) == 0)
        return (TRUE);
    else
    {
        printf("------------------------------\n");
        printf("Different %soutput%s\n", YELLOW, NONE);
        printf("├── %sft_printf(\"%s\", %s) => \"%s\"%s\n", RED, input_format, input_value, got, NONE);
        printf("└───── printf(\"%s\", %s) => \"%s\"\n", input_format, input_value, expected);
        printf("------------------------------\n");
        return (FALSE);
    }
}

void print_results(void)
{
    if (g_failed == 0)
        printf("===> ✅ %s%d / %d tests passed%s\n", GREEN, g_passed, g_total, NONE);
    else
        printf("===> ❌ %s%d / %d tests failed%s\n", RED, g_failed, g_total, NONE);
}
