#include "libftprintf.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	write(1, "printf   --->", 13);
	printf("%.03s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("%.03s", (char *)NULL);
	write(1, "<---\n\n", 6);

	write(1, "printf   --->", 13);
	printf("%3.1s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("%3.1s", (char *)NULL);
	write(1, "<---\n\n", 6);
	
	write(1, "printf   --->", 13);
	printf("%9.1s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("%9.1s", (char *)NULL);
	write(1, "<---\n\n", 6);
	
	write(1, "printf   --->", 13);
	printf("%-3.1s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("%-3.1s", (char *)NULL);
	write(1, "<---\n\n", 6);
	
	write(1, "printf   --->", 13);
	printf("%-9.1s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("%-9.1s", (char *)NULL);
	write(1, "<---\n\n", 6);
	
	write(1, "printf   --->", 13);
	printf("p3 %.4s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("p3 %.4s", (char *)NULL);
	write(1, "<---\n\n", 6);
	
	write(1, "printf   --->", 13);
	printf("%50.2s", (char *)NULL);
	write(1, "<---\nft_printf --->", 19);
	ft_printf("%50.2s", (char *)NULL);
	write(1, "<---\n\n", 6);
}
