- Add exit codes to forked expects
- Add auto-find of header files

- Add `test.zsh` launcher (update `Makefile`, run tests, then restore original `Makefile` ?)

- Add **NULL** test everywhere it's possible
- Add **overflow** test everywhere it's possible
- Add **mix** formats `"my %s is %d long and %i large for %u time (%x or %X in hex) and points to %p"`
- Vérifier que tous les retours de `write()` sont bien checkés au cas où le syscall échoue
- Add test with `stdout` redirected to `/dev/full` ?