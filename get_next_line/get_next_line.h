/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:01:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/05 06:51:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TRUE 1
# define FALSE 0
# define ERROR -1

# ifdef EOF
#  undef EOF
# endif
# define EOF (void *)42

# include <stddef.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	char			*ptr;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*read_line(t_list *node, int fd);
char	*get_str(int fd, size_t len_total);
t_list	*init_node(t_list **head, int fd);
void	del_node(t_list **head, int fd);

char	*ft_strjoin(char *s1, char *s2);
void	ft_memcpy(char *dst, char *src, size_t n);
char	*ft_strchr(char *s, int c);
size_t	get_len(char *str);
void	adjust(t_list *node, char *new);

#endif
