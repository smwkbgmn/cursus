/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:01:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 16:13:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define ERROR -1

# include <stdlib.h>
# include <stddef.h>

typedef struct s_fd
{
	int			fd;
	char		*str;
	char		*ptr;
	struct s_fd	*next;
}	t_fd;

char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(char *s, int c);
void	gnl_memcpy(char *dst, char *src, size_t n);
void	adjust_node(t_fd *node, char *new);

#endif
