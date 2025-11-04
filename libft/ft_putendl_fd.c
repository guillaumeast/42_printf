#include "libft.h"

/*
Outputs the string ’s’ to the given file descriptor followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
