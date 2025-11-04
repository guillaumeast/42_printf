/*
Converts a lower-case letter to the corresponding upper-case letter.
The argument must be representable as an unsigned char or the value of EOF.

If the argument is a lower-case letter, it returns the corresponding upper-case letter if there is one.
Otherwise, the argument is returned unchanged.
*/
int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'a' && uc <= 'z')
		return (uc - 32);
	return (c);
}
