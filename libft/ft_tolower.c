/*
Converts an upper-case letter to the corresponding lower-case letter.
The argument must be representable as an unsigned char or the value of EOF.

If the argument is an upper-case letter, it returns the corresponding lower-case letter if there is one.
Otherwise, the argument is returned unchanged.
*/
int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc + 32);
	return (c);
}
