#include "libft.h"

/*
Outputs the string ’s’ to the given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
