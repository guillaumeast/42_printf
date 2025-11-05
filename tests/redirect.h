#ifndef REDIRECT_H
# define REDIRECT_H

# include "tests.h"

# define OUT_MAX 1024

typedef struct s_redirect {
	int		original_fd_copy;
	FILE	*tmp_file;
	int		tmp_fd;
}	t_redirect;

static inline void	redirect_start(t_redirect *r)
{
	r->original_fd_copy = dup(STDOUT_FILENO);
	r->tmp_file = tmpfile();
	r->tmp_fd = fileno(r->tmp_file);
	dup2(r->tmp_fd, STDOUT_FILENO);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(r->tmp_file, NULL, _IONBF, 0);
}

static inline size_t	redirect_read(t_redirect *r, char *buf)
{
	size_t	n;

	fseek(r->tmp_file, 0, SEEK_SET);
	n = fread(buf, 1, OUT_MAX - 1, r->tmp_file);
	buf[n] = '\0';
	return (n);
}

static inline void	redirect_clear(t_redirect *r)
{
	ftruncate(r->tmp_fd, 0);
	fseek(r->tmp_file, 0, SEEK_SET);
}

static inline void	redirect_stop(t_redirect *r)
{
	dup2(r->original_fd_copy, STDOUT_FILENO);
	close(r->original_fd_copy);
	fclose(r->tmp_file);
}

#endif
