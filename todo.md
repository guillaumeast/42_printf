- Add **NULL** test everywhere it's possible
- Add **overflow** test everywhere it's possible
- Add **mix** formats `"my %s is %d long and %i large for %u time (%x or %X in hex) and points to %p"`
- Vérifier que tous les retours de write() sont bien checkés au cas où le syscall échoue
- Add test with `stdout` redirected to `/dev/full` ?

- Add `42 headers` (with vscode plugin)

- Create `42_ultimate_printf_tester` repo with **curlable** `sh` script
	- Downloads `tests/` dir (depending on tested project: `libft`, `printf`...)
	- Backups original `Makefile`
	- Adds a `42_breaker` rule to `Makefile` which compiles project with `criterion` and run tests
	- Adds a `restore` rule to `Makefile` to delete `tests/` dir and restore original `Makefile` and run `make fclean`
