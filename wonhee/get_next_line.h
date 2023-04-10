#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ERROR -1

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
int 	ft_strchr(char *str, int c);
char	*ft_substr(char const *s, int stasrt, int len);
int 	ft_strlen(const char *str);
char    *get_next_line(int fd);

char	*read_buf(int fd, char **data, char *buf, int size);
char	*size_is_zero(char **data);
char	*devide_line(char **data);

void	ft_free(char **ptr);

#endif