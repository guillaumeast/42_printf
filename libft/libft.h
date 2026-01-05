/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gastesan <gastesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:34:40 by gastesan          #+#    #+#             */
/*   Updated: 2025/12/12 23:04:58 by gastesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>	// size_t
# include <stdbool.h>	// bool

typedef struct s_buff
{
	char	*data;
	size_t	cap;
	size_t	len;
}	t_buff;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*--------- BUFF ----------*/

bool	buff_init(t_buff *b, size_t initial_cap);
bool	buff_prepend(t_buff *b, const char *str, long n);
bool	buff_insert(t_buff *b, size_t index, const char *str, long n);
bool	buff_append(t_buff *b, const char *str, long n);
void	buff_free(t_buff *b);

/*---------- CHR ----------*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
bool	ft_isincharset(char c, const char *charset);
int		ft_isprint(int c);
int		ft_isspace(char c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*--------- CONV ----------*/

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_ltoa(long n);
char	*ft_ultoa_base(unsigned long n, const char *base);

/*---------- LST ----------*/

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*--------- MALLOC --------*/

void	*ft_calloc(size_t count, size_t size);
bool	ft_realloc(char **buff, size_t cap, size_t newcap);

/*---------- MEM ----------*/

void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*---------- PUT ----------*/

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*---------- STR ----------*/

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
