#include "libft.h"

/*
Takes the full size of the destination buffer and guarantee NUL-termination if there is room.
Room for the NUL should be included in dstsize.
Only operates on true ''C'' strings: src must be NUL-terminated.

Returns the length of src.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
