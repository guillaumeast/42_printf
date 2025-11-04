/*
Tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
