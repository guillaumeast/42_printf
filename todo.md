- Add **test suite** feature
- Add **timeout** feature
- Add **crash** feature
- Add `test.zsh` launcher (update `Makefile`, run tests, then restore original `Makefile` ?)

- Add **NULL** test everywhere it's possible
- Add **overflow** test everywhere it's possible
- Add **mix** formats `"my %s is %d long and %i large for %u time (%x or %X in hex) and points to %p"`
- Vérifier que tous les retours de `write()` sont bien checkés au cas où le syscall échoue
- Add test with `stdout` redirected to `/dev/full` ?

## 42_ultimate_printf_tester

- Create `42_ultimate_printf_tester` public repo with **curlable** `sh` script

```bash
curl -fsSL https://raw.githubusercontent.com/guillaumeast/42_ultimate_printf_tester/refs/heads/master/install.sh | sh
```

0. Check project integrity (TODO: check `NAME` inside `Makefile`)
```bash
if [ ! -f "Makefile" ]; then
  echo "⚠️  This doesn’t look like an ft_printf project."
  read -p "Continue anyway? [y/N] " yn
  [[ $yn == [Yy]* ]] || exit 1
fi
```

1. Downloads `tests/` dir
```bash
curl -L https://github.com/guillaumeast/42_ultimate_printf_tester/raw/master/tests.tar.gz | tar -xz
```

2. Downloads `Criterion` into `tests/Criterion` with `curl`
```bash
LATEST=$(curl -s https://api.github.com/repos/Snaipe/Criterion/releases/latest | grep tag_name | cut -d '"' -f4)
URL="https://github.com/Snaipe/Criterion/releases/download/$LATEST/criterion-${LATEST#v}-linux-x86_64.tar.xz"
curl -L $URL | tar -xJ
mv criterion-* tests/Criterion
```

3. Backups original `Makefile` to `backup.Makefile`
```bash
cp Makefile backup.Makefile 2>/dev/null || echo "No Makefile found."
```

4. Updates `Makefile` to add `ultimate_test` rule (which compiles project with `criterion` and run tests)
```Makefile
# === Ultimate Printf Tester ===
ultimate_test:
	cc -Wall -Wextra -Werror \
		-Itests/Criterion/include -Ltests/Criterion/lib -lcriterion \
		tests/*.c -o run_tests $(SRCS)
	./run_tests
# ==============================
```

5. Updates `Makefile` to add a `restore` rule to delete `tests/` dir + restore original `Makefile` + run `make fclean`
```Makefile
restore:
	rm -rf tests
	mv -f backup.Makefile Makefile
	make fclean
```
