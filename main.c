#include "libftprintf.h"

int main(void)
{
	ft_printf("Should be valid:\n");
    ft_printf("%c %s %d %i %u %%.\n", 'a', "bcd", -12, -34, 56);
	ft_printf("\nShould NOT be valid:\n");
    ft_printf("%c %u %_.\n", -12, -34);
    return (0);
}
