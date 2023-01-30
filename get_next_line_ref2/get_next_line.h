/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:01:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/30 03:08:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_list
{
	struct s_list	*next;
	int				fd;
	char			*str;
	char			*ptr;
}	t_list;

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_memcpy(char *dst, char *src, size_t n);
t_list	*init_list(int fd);
size_t	get_len_line(char *ptr);
size_t	ft_strlen(char *s);
short	is_there_nl(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
