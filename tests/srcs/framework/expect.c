#include "expect.h"

static int passed = 0;
static int failed = 0;
static int total  = 0;

void expect_init(void)
{
    passed = failed = total = 0;
    printf("\n");
}

void expect_eq_int(int got, int expected, const char *input_format, const char *input_value)
{
    total++;
    if (got == expected)
        passed++;
    else
    {
        printf("------------------------------\n");
        printf("Different %sreturn value%s\n", YELLOW, NONE);
        printf("├── %sft_printf(\"%s\", %s) = %d%s\n", RED, input_format, input_value, got, NONE);
        printf("└───── printf(\"%s\", %s) = %d\n", input_format, input_value, expected);
        printf("------------------------------\n");
        failed++;
    }
}

void expect_str_eq(const char *got, const char *expected, const char *input_format, const char *input_value)
{
    total++;
    if (strcmp(got, expected) == 0)
    {
        passed++;
    }
    else
    {
        printf("------------------------------\n");
        printf("Different %soutput%s\n", YELLOW, NONE);
        printf("├── %sft_printf(\"%s\", %s) => \"%s\"%s\n", RED, input_format, input_value, got, NONE);
        printf("└───── printf(\"%s\", %s) => \"%s\"\n", input_format, input_value, expected);
        printf("------------------------------\n");
        failed++;
    }
}

void print_results(void)
{
    printf("\n");
    if (failed == 0)
        printf("===> ✅ %s%d / %d tests passed%s\n", GREEN, passed, total, NONE);
    else
        printf("===> ❌ %s%d / %d tests failed%s\n", RED, failed, total, NONE);
}
