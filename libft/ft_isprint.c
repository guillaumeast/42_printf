/*
Tests for any printing character, including space (‘ ’).
The value of the argument must be representable as an unsigned char or the value of EOF.

Returns zero if the character tests false and returns non-zero if the character tests true.
*/
int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}
