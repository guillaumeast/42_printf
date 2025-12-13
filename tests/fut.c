#include "fut.h"
#include "libftprintf.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define COL_GREEN	"\033[32m"
#define COL_RED		"\033[31m"
#define COL_NO		"\033[0m"

Test(fut_basics, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, (""));
	compare(RET_OUT, 1, ft_printf, printf, ("a"));
	compare(RET_OUT, 1, ft_printf, printf, ("Hello world"));
	compare(RET_OUT, 1, ft_printf, printf, ("\t\n\r\v\f\n\t\n\r\v\f\n"));
	compare(RET_OUT, 1, ft_printf, printf, (COL_RED "Colored string" COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, ("Multi " COL_RED "colored" COL_GREEN " string" COL_NO));
}

Test(fut_percent, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%%"));
	compare(RET_OUT, 1, ft_printf, printf, (" %%"));
	compare(RET_OUT, 1, ft_printf, printf, ("%% "));
	compare(RET_OUT, 1, ft_printf, printf, (" %% "));
	compare(RET_OUT, 1, ft_printf, printf, ("%%%%"));
	compare(RET_OUT, 1, ft_printf, printf, (" %%%%"));
	compare(RET_OUT, 1, ft_printf, printf, ("%%%% "));
	compare(RET_OUT, 1, ft_printf, printf, (" %%%% "));
	compare(RET_OUT, 1, ft_printf, printf, ("%%%%%%"));
	compare(RET_OUT, 1, ft_printf, printf, ("c%%"));
	compare(RET_OUT, 1, ft_printf, printf, ("%%c"));
	compare(RET_OUT, 1, ft_printf, printf, (" %%c "));
	compare(RET_OUT, 1, ft_printf, printf, ("c%%c%%c"));
	compare(RET_OUT, 1, ft_printf, printf, (" %%c%% "));
	compare(RET_OUT, 1, ft_printf, printf, ("c%%c%%c%%c"));
	compare(RET_OUT, 1, ft_printf, printf, (" c%%c%%c%%c "));
	compare(RET_OUT, 1, ft_printf, printf, ("%%\t%%\n%%\r%%\v%%\f%%\n%%\t%%\n%%\r%%\v%%\f%%\n%%"));
}

Test(fut_c, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%c", -256));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", -255));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", -1));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", -0));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 0));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", +0));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 1));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 32));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 33));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 126));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 127));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 255));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", 256));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", UINT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%c", '\0'));
	compare(RET_OUT, 1, ft_printf, printf, (" %c", '\0'));
	compare(RET_OUT, 1, ft_printf, printf, (" %c ", '\0'));
	compare(RET_OUT, 1, ft_printf, printf, (" %c ", '\0'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\n', '\n', '\n', '\n', '\n', '\n', '\n', '\n', '\n', '\n', '\n', '\n', '\n'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\r', '\r', '\r', '\r', '\r', '\r', '\r', '\r', '\r', '\r', '\r', '\r', '\r'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\v', '\v', '\v', '\v', '\v', '\v', '\v', '\v', '\v', '\v', '\v', '\v', '\v'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\f', '\f', '\f', '\f', '\f', '\f', '\f', '\f', '\f', '\f', '\f', '\f', '\f'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\t', '\n', '\r', '\v', '\f', '\n', '\t', '\n', '\r', '\v', '\f', '\n', '\n'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c", '\n', '\t', '\n', '\r', '\v', '\f', '\n', '\t', '\n', '\r', '\v', '\f', '\n'));
}

Test(fut_s, 0)
{
	static char	dumb_chars[14];

	dumb_chars[0] = (char)-256;
	dumb_chars[1] = (char)-255;
	dumb_chars[2] = (char)-1;
	dumb_chars[3] = (char)-0;
	dumb_chars[4] = (char)0;
	dumb_chars[5] = (char)+0;
	dumb_chars[6] = (char)1;
	dumb_chars[7] = (char)32;
	dumb_chars[8] = (char)33;
	dumb_chars[9] = (char)126;
	dumb_chars[10] = (char)127;
	dumb_chars[11] = (char)255;
	dumb_chars[12] = (char)256;
	dumb_chars[13] = '\0';

	compare(RET_OUT, 1, ft_printf, printf, ("%s", ""));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", " "));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", "Hello world"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	compare(RET_OUT, 1, ft_printf, printf, ("s%ss", "Hello world"));
	compare(RET_OUT, 1, ft_printf, printf, ("s%ss%ss", "Hello", " world"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", "\t\n\r\v\f\n\t\n\r\v\f\n"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, ("%s%s", COL_RED, COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, (COL_RED "%s" COL_NO, "Colored string"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s" COL_RED "%s" COL_GREEN "%s" COL_NO, "Multi ", "colored", " string"));
	compare(RET_OUT, 1, ft_printf, printf, ("%sColored string%s", COL_RED, COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, ("Multi %scolored %sstring%s", COL_RED, COL_GREEN, COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "s", "s", "s", "s", "s", "s", "s", "s", "s", "s", "s", "s", "s"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t", "\t"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\n", "\n", "\n", "\n", "\n", "\n", "\n", "\n", "\n", "\n", "\n", "\n", "\n"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\r", "\r", "\r", "\r", "\r", "\r", "\r", "\r", "\r", "\r", "\r", "\r", "\r"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\v", "\v", "\v", "\v", "\v", "\v", "\v", "\v", "\v", "\v", "\v", "\v", "\v"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\f", "\f", "\f", "\f", "\f", "\f", "\f", "\f", "\f", "\f", "\f", "\f", "\f"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\t", "\n", "\r", "\v", "\f", "\n", "\t", "\n", "\r", "\v", "\f", "\n", "\n"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s", "\n", "\t", "\n", "\r", "\v", "\f", "\n", "\t", "\n", "\r", "\v", "\f", "\n"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s%s%s%s%s%s%s%s%s", "%%", "%c", "%s", "%d", "%i", "%u", "%x", "%X", "%p"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", dumb_chars));
	compare(RET_OUT, 1, ft_printf, printf, ("%s", (char *)NULL));
	compare(RET_OUT, 1, ft_printf, printf, ("s%ss%ss", (char *)NULL, (char *)NULL));
}

Test(fut_d, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%d", -1));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", -0));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", 0));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", +0));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", +1));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%d", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("d%dd", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%d%d%dd", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%dd%dd%dd", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%d\t%d\n%d\r%d\v%d\f%d", 42, 42, 42, 42, 42, 42));
}

Test(fut_i, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%i", -1));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", -0));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", 0));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", +0));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", +1));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%i", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("d%id", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%i%i%id", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%id%id%id", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%i\t%i\n%i\r%i\v%i\f%i", 42, 42, 42, 42, 42, 42));
}

Test(fut_u, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%u", 0));
	compare(RET_OUT, 1, ft_printf, printf, ("%u", +0));
	compare(RET_OUT, 1, ft_printf, printf, ("%u", +1));
	compare(RET_OUT, 1, ft_printf, printf, ("%u", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%u", INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%u", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%u", UINT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("d%ud", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%u%u%ud", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%ud%ud%ud", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%u\t%u\n%u\r%u\v%u\f%u", 42, 42, 42, 42, 42, 42));
}

Test(fut_x, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%x", 0));
	compare(RET_OUT, 1, ft_printf, printf, ("%x", +0));
	compare(RET_OUT, 1, ft_printf, printf, ("%x", +1));
	compare(RET_OUT, 1, ft_printf, printf, ("%x", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%x", INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%x", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%x", UINT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("d%xd", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%x%x%xd", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%xd%xd%xd", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%x\t%x\n%x\r%x\v%x\f%x", 42, 42, 42, 42, 42, 42));
}

Test(fut_X, 0)
{
	compare(RET_OUT, 1, ft_printf, printf, ("%X", 0));
	compare(RET_OUT, 1, ft_printf, printf, ("%X", +0));
	compare(RET_OUT, 1, ft_printf, printf, ("%X", +1));
	compare(RET_OUT, 1, ft_printf, printf, ("%X", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%X", INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%X", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%X", UINT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("d%Xd", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%X%X%Xd", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%Xd%Xd%Xd", 42, 42, 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%X\t%X\n%X\r%X\v%X\f%X", 42, 42, 42, 42, 42, 42));
}

Test(fut_p, 0)
{
	int stack = 42;
	int	*heap;

	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)+1));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)42));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)INT_MIN));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)UINT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("d%pd", (void *)42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%p%p%pd", (void *)42, (void *)42, (void *)42));
	compare(RET_OUT, 1, ft_printf, printf, ("d%pd%pd%pd", (void *)42, (void *)42, (void *)42));
	compare(RET_OUT, 1, ft_printf, printf, ("%p\t%p\n%p\r%p\v%p\f%p", (void *)42, (void *)42, (void *)42, (void *)42, (void *)42, (void *)42));
	compare(RET_OUT, 1, ft_printf, printf, ("func adrr: %p", &printf));
	compare(RET_OUT, 1, ft_printf, printf, ("stack adrr: %p", &stack));
	
	heap = malloc(sizeof heap);
	if (!heap)
	{
		print_stderr("❗️ " COL_RED "Internal error: not enough memory\n" COL_NO);
		exit(EXIT_FAILURE);
	}
	compare(RET_OUT, 1, ft_printf, printf, ("heap addr: %p", &heap));
	free(heap);

	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)-1));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)-0));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)0));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)+0));
	compare(RET_OUT, 1, ft_printf, printf, ("%p", (void *)NULL));
}

Test(fut_mix, 0)
{
	static char mid_null[] = "ABC\0DEF";
	int x = 42;

	compare(RET_OUT, 1, ft_printf, printf, ("%c%s%d", 'A', "bc", 42));
	compare(RET_OUT, 1, ft_printf, printf, ("%s%c%i", ">", '<', -1));
	compare(RET_OUT, 1, ft_printf, printf, ("%u%s%x", 0, " - ", 255));
	compare(RET_OUT, 1, ft_printf, printf, ("%c%s%c", '\0', "mid", '\0'));
	compare(RET_OUT, 1, ft_printf, printf, ("%s %c %s", COL_RED, '\0', COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, ("%c%s%s", '\0', COL_RED, COL_NO));
	compare(RET_OUT, 1, ft_printf, printf, ("%d %s %d", INT_MIN, "mid", INT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%u %s %u", 0u, "-", UINT_MAX));
	compare(RET_OUT, 1, ft_printf, printf, ("%x %s %X", 0xabcdef, " | ", 0xABCDEF));
	compare(RET_OUT, 1, ft_printf, printf, ("%p-%d-%s", &x, 42, "ok"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s %p %c", "ptr:", &x, 'A'));
	compare(RET_OUT, 1, ft_printf, printf, ("%p %p %d", &x, NULL, -1));
	compare(RET_OUT, 1, ft_printf, printf, ("%c%s%d%i%u%x%X%p", 'A', "B", 1, -2, 3u, 0x4, 0x5, (void*)42));
	compare(RET_OUT, 1, ft_printf, printf, ("%s\t%c\n%d\r%s\v%u\f%x", "S", 'X', -42, "T", 123u, 0xFF));
	compare(RET_OUT, 1, ft_printf, printf, ("%s-%d-%c", mid_null, 42, 'Z'));
	compare(RET_OUT, 1, ft_printf, printf, ("%c%s%s", '>', mid_null, "<"));
	compare(RET_OUT, 1, ft_printf, printf, ("%s-%c-%d", (char*)NULL, 'A', 1));
	compare(RET_OUT, 1, ft_printf, printf, ("%d %s %p", 42, (char*)NULL, NULL));
	compare(RET_OUT, 1, ft_printf, printf, ("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%p%%", 'A', "42", -1, 2, 3u, 0xA, 0xB, (void*)42));
}

void	run_all_test_cases(void)
{
	int 		stack = 42;
	static char	mid_null[] = "ABC\0DEF";
	static char	dumb_chars[14];

	dumb_chars[0] = (char)-256;
	dumb_chars[1] = (char)-255;
	dumb_chars[2] = (char)-1;
	dumb_chars[3] = (char)-0;
	dumb_chars[4] = (char)0;
	dumb_chars[5] = (char)+0;
	dumb_chars[6] = (char)1;
	dumb_chars[7] = (char)32;
	dumb_chars[8] = (char)33;
	dumb_chars[9] = (char)126;
	dumb_chars[10] = (char)127;
	dumb_chars[11] = (char)255;
	dumb_chars[12] = (char)256;
	dumb_chars[13] = '\0';

	redirect_start(R_BOTH);

	/* fut_basics */
	ft_printf("");
	ft_printf("a");
	ft_printf("Hello world");
	ft_printf("\t\n\r\v\f\n\t\n\r\v\f\n");
	ft_printf(COL_RED "Colored string" COL_NO);
	ft_printf("Multi " COL_RED "colored" COL_GREEN " string" COL_NO);

	/* fut_percent */
	ft_printf("%%");
	ft_printf(" %%");
	ft_printf("%% ");
	ft_printf(" %% ");
	ft_printf("%%%%");
	ft_printf(" %%%%");
	ft_printf("%%%% ");
	ft_printf(" %%%% ");
	ft_printf("%%%%%%");
	ft_printf("c%%");
	ft_printf("%%c");
	ft_printf(" %%c ");
	ft_printf("c%%c%%c");
	ft_printf(" %%c%% ");
	ft_printf("c%%c%%c%%c");
	ft_printf(" c%%c%%c%%c ");
	ft_printf("%%\t%%\n%%\r%%\v%%\f%%\n%%\t%%\n%%\r%%\v%%\f%%\n%%");

	/* fut_c */
	ft_printf("%c", -256);
	ft_printf("%c", -255);
	ft_printf("%c", -1);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c", +0);
	ft_printf("%c", 1);
	ft_printf("%c", 32);
	ft_printf("%c", 33);
	ft_printf("%c", 126);
	ft_printf("%c", 127);
	ft_printf("%c", 255);
	ft_printf("%c", 256);
	ft_printf("%c", INT_MIN);
	ft_printf("%c", INT_MAX);
	ft_printf("%c", UINT_MAX);
	ft_printf("%c", '\0');
	ft_printf(" %c", '\0');
	ft_printf(" %c ", '\0');
	ft_printf(" %c ", '\0');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'c','c','c','c','c','c','c','c','c','c','c','c','c');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\t','\t','\t','\t','\t','\t','\t','\t','\t','\t','\t','\t','\t');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\r','\r','\r','\r','\r','\r','\r','\r','\r','\r','\r','\r','\r');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\v','\v','\v','\v','\v','\v','\v','\v','\v','\v','\v','\v','\v');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\f','\f','\f','\f','\f','\f','\f','\f','\f','\f','\f','\f','\f');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\t','\n','\r','\v','\f','\n','\t','\n','\r','\v','\f','\n','\n');
	ft_printf("%c\t%c\n%c\r%c\v%c\f%c\n%c\t%c\n%c\r%c\v%c\f%c\n%c",
		'\n','\t','\n','\r','\v','\f','\n','\t','\n','\r','\v','\f','\n');

	/* fut_s */
	ft_printf("%s", "");
	ft_printf("%s", " ");
	ft_printf("%s", "Hello world");
	ft_printf("%s", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ft_printf("s%ss", "Hello world");
	ft_printf("s%ss%ss", "Hello", " world");
	ft_printf("%s", "\t\n\r\v\f\n\t\n\r\v\f\n");
	ft_printf("%s", COL_NO);
	ft_printf("%s%s", COL_RED, COL_NO);
	ft_printf(COL_RED "%s" COL_NO, "Colored string");
	ft_printf("%s" COL_RED "%s" COL_GREEN "%s" COL_NO,
		"Multi ", "colored", " string");
	ft_printf("%sColored string%s", COL_RED, COL_NO);
	ft_printf("Multi %scolored %sstring%s",
		COL_RED, COL_GREEN, COL_NO);
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"s","s","s","s","s","s","s","s","s","s","s","s","s");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\t","\t","\t","\t","\t","\t","\t","\t","\t","\t","\t","\t","\t");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\n","\n","\n","\n","\n","\n","\n","\n","\n","\n","\n","\n","\n");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\r","\r","\r","\r","\r","\r","\r","\r","\r","\r","\r","\r","\r");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\v","\v","\v","\v","\v","\v","\v","\v","\v","\v","\v","\v","\v");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\f","\f","\f","\f","\f","\f","\f","\f","\f","\f","\f","\f","\f");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\t","\n","\r","\v","\f","\n","\t","\n","\r","\v","\f","\n","\n");
	ft_printf("%s\t%s\n%s\r%s\v%s\f%s\n%s\t%s\n%s\r%s\v%s\f%s\n%s",
		"\n","\t","\n","\r","\v","\f","\n","\t","\n","\r","\v","\f","\n");
	ft_printf("%s%s%s%s%s%s%s%s%s",
		"%%","%c","%s","%d","%i","%u","%x","%X","%p");
	ft_printf("%s", dumb_chars);
	ft_printf("%s", (char *)NULL);
	ft_printf("s%ss%ss", (char *)NULL, (char *)NULL);

	/* fut_d */
	ft_printf("%d", -1);
	ft_printf("%d", -0);
	ft_printf("%d", 0);
	ft_printf("%d", +0);
	ft_printf("%d", +1);
	ft_printf("%d", 42);
	ft_printf("%d", INT_MIN);
	ft_printf("%d", INT_MAX);
	ft_printf("d%dd", 42);
	ft_printf("d%d%d%dd", 42,42,42);
	ft_printf("d%dd%dd%dd", 42,42,42);
	ft_printf("%d\t%d\n%d\r%d\v%d\f%d",
		42,42,42,42,42,42);

	/* fut_i */
	ft_printf("%i", -1);
	ft_printf("%i", -0);
	ft_printf("%i", 0);
	ft_printf("%i", +0);
	ft_printf("%i", +1);
	ft_printf("%i", 42);
	ft_printf("%i", INT_MIN);
	ft_printf("%i", INT_MAX);
	ft_printf("d%id", 42);
	ft_printf("d%i%i%id", 42,42,42);
	ft_printf("d%id%id%id", 42,42,42);
	ft_printf("%i\t%i\n%i\r%i\v%i\f%i",
		42,42,42,42,42,42);

	/* fut_u */
	ft_printf("%u", 0);
	ft_printf("%u", +0);
	ft_printf("%u", +1);
	ft_printf("%u", 42);
	ft_printf("%u", INT_MIN);
	ft_printf("%u", INT_MAX);
	ft_printf("%u", UINT_MAX);
	ft_printf("d%ud", 42);
	ft_printf("d%u%u%ud", 42,42,42);
	ft_printf("d%ud%ud%ud", 42,42,42);
	ft_printf("%u\t%u\n%u\r%u\v%u\f%u",
		42,42,42,42,42,42);
	ft_printf("%u", -1);
	ft_printf("%u", -0);

	/* fut_x */
	ft_printf("%x", 0);
	ft_printf("%x", +0);
	ft_printf("%x", +1);
	ft_printf("%x", 42);
	ft_printf("%x", INT_MIN);
	ft_printf("%x", INT_MAX);
	ft_printf("%x", UINT_MAX);
	ft_printf("d%xd", 42);
	ft_printf("d%x%x%xd", 42,42,42);
	ft_printf("d%xd%xd%xd", 42,42,42);
	ft_printf("%x\t%x\n%x\r%x\v%x\f%x",
		42,42,42,42,42,42);
	ft_printf("%x", -1);
	ft_printf("%x", -0);

	/* fut_X */
	ft_printf("%X", 0);
	ft_printf("%X", +0);
	ft_printf("%X", +1);
	ft_printf("%X", 42);
	ft_printf("%X", INT_MIN);
	ft_printf("%X", INT_MAX);
	ft_printf("%X", UINT_MAX);
	ft_printf("d%Xd", 42);
	ft_printf("d%X%X%Xd", 42,42,42);
	ft_printf("d%Xd%Xd%Xd", 42,42,42);
	ft_printf("%X\t%X\n%X\r%X\v%X\f%X",
		42,42,42,42,42,42);
	ft_printf("%X", -1);
	ft_printf("%X", -0);

	/* fut_p */
	ft_printf("%p", (void *)+1);
	ft_printf("%p", (void *)42);
	ft_printf("%p", (void *)INT_MIN);
	ft_printf("%p", (void *)INT_MAX);
	ft_printf("%p", (void *)UINT_MAX);
	ft_printf("d%pd", (void *)42);
	ft_printf("d%p%p%pd",
		(void *)42, (void *)42, (void *)42);
	ft_printf("d%pd%pd%pd",
		(void *)42, (void *)42, (void *)42);
	ft_printf("%p\t%p\n%p\r%p\v%p\f%p",
		(void *)42,(void *)42,(void *)42,
		(void *)42,(void *)42,(void *)42);
	ft_printf("stack adrr: %p", &stack);

	ft_printf("%p", (void *)-1);
	ft_printf("%p", (void *)-0);
	ft_printf("%p", (void *)0);
	ft_printf("%p", (void *)+0);
	ft_printf("%p", (void *)NULL);

	/* fut_mix */
	ft_printf("%c%s%d", 'A', "bc", 42);
	ft_printf("%s%c%i", ">", '<', -1);
	ft_printf("%u%s%x", 0, " - ", 255);
	ft_printf("%c%s%c", '\0', "mid", '\0');
	ft_printf("%s %c %s", COL_RED, '\0', COL_NO);
	ft_printf("%c%s%s", '\0', COL_RED, COL_NO);
	ft_printf("%d %s %d", INT_MIN, "mid", INT_MAX);
	ft_printf("%u %s %u", 0u, "-", UINT_MAX);
	ft_printf("%x %s %X", 0xabcdef, " | ", 0xABCDEF);
	ft_printf("%p-%d-%s", &stack, 42, "ok");
	ft_printf("%s %p %c", "ptr:", &stack, 'A');
	ft_printf("%p %p %d", &stack, NULL, -1);
	ft_printf("%c%s%d%i%u%x%X%p", 'A', "B", 1, -2, 3u, 0x4, 0x5, (void*)42);
	ft_printf("%s\t%c\n%d\r%s\v%u\f%x", "S", 'X', -42, "T", 123u, 0xFF);
	ft_printf("%s-%d-%c", mid_null, 42, 'Z');
	ft_printf("%c%s%s", '>', mid_null, "<");
	ft_printf("%s-%c-%d", (char*)NULL, 'A', 1);
	ft_printf("%d %s %p", 42, (char*)NULL, NULL);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%p%%", 'A', "42", -1, 2, 3u, 0xA, 0xB, (void*)42);

	redirect_stop();
}

Test(fut_mem_leaks, 0)
{
	memleaks(10, run_all_test_cases());
}

Test(fut_mem_safety, 0)
{
	memsafety(10, run_all_test_cases());
}
