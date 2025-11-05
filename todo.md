- Add `42 headers` (with vscode plugin)

- Create `42_breaker` repo with **curlable** `sh` script
	- Downloads `tests/` dir (depending on tested project: `libft`, `printf`...)
	- Backups original `Makefile`
	- Adds a `42_breaker` rule to `Makefile` which compiles project with `criterion` and run tests
	- Adds a `restore` rule to `Makefile` to delete `tests/` dir and restore original `Makefile` and run `make fclean`
