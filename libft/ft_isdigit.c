/*
Tests for a decimal digit character.
The value of the argument must be representable as an unsigned char or the value of EOF.

Returns zero if the character tests false and return non-zero if the character tests true.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
