- Add install/update libft script (inside libft repo)
	- `rm -rf libft`
	- `git clone https://github.com/guillaumeast/42_libft libft`
	- `rm -rf libft/.git libft/subject libft/tests`
	- `rm .gitignore`
> `curl https://github.com/guillaumeast/42_libft/install.sh | sh` to install/update libft anywhere

- Update	libft `ft_putchar_fd()` => cast `int` to `unsigned char`
- Add		libft `ft_putnbr_unsigned_fd()`
- Add		libft `ft_putnbr_base_fd()`
- Add		libft `ft_putnbr_unsigned_base_fd()`
- Check		libft all implementations
- Add		libft enforced test cases

- Add		printf return value `int`
- Add		printf `Makefile`
