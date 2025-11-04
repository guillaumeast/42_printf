#include "libft.h"

/*
Takes the full size of the destination buffer and guarantee NUL-termination if there is room.
Room for the NUL should be included in dstsize.
Only operates on true ''C'' strings: both src and dst() must be NUL-terminated.
Appends string src to the end of dst.
It will append at most dstsize - strlen(dst) - 1 characters.
It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize.

Returns the total length of the string they tried to create. 
That means the initial length of dst plus the length of src.
If the return value is >= dstsize, the output string has been truncated.
It is the caller's responsibility to handle this.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (dst_len + i < dstsize - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
