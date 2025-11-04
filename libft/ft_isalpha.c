/*
Tests for any character for which isupper(3) or islower(3) is true.
The value of the argument must be representable as an unsigned char or the value of EOF.

Returns zero if the character tests false and returns non-zero if the character tests true.
*/
int	ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
