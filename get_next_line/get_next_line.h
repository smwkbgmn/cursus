/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:01:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/31 04:20:15 by donghyu2         ###   ########.fr       */
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

t_list	*init_list(int fd);
size_t	get_len(char *str);
short	is_there_nl(char *str);
void	ft_strncpy(char *dst, char *src, size_t n);
void	set_new_str(t_list *node, char *str);
#endif
