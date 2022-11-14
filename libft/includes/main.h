#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <ctype.h>

// libc
int		ft_isalpha(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// additional
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const 	*s1, char const *s2);
char 	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const  *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);