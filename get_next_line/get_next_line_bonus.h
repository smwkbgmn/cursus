/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:01:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/04 03:56:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define ERROR -1
# define WRONG_FD (void *)42

# include <stddef.h>

typedef struct s_list
{
	struct s_list	*next;
	int				fd;
	char			*str;
	char			*ptr;
}	t_list;

char	*get_next_line(int fd);
char	*read_line(t_list *node, int fd);
char	*get_str(int fd, size_t len_total);
t_list	*init_list(t_list **head, int fd);
void	ft_lstdel(t_list **head, int fd);

char	*ft_strchr(char *s, int c);
void	ft_strncpy(char *dst, char *src, size_t n);
char	*ft_calloc(size_t count, size_t size);
size_t	get_len(char *str);
void	adjust(t_list *node, char *new, size_t len_p, size_t len_n);

#endif
