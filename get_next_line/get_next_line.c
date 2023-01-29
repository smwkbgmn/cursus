/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/29 21:53:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Consider standard input (fd 1)
// Read buf size will be modified during evaluation
// compiler buf size flag : -D BUFFER_SIZE=n

#include <stdio.h>

#include "get_next_line.h"

char	*read_line(t_list *node, int fd);
char	*get_str(int fd, size_t len_total);
short	is_there_nl(char *str);

char	*get_next_line(int fd)
{
	static t_list	*node;
	char			*line;

	node = init_list(fd);
	line = read_line(node, fd);
	return (line);
}

char	*read_line(t_list *node, int fd)
{
	char	*str;
	char	*line;
	size_t	len_line;

	if (!node->str || !is_there_nl(node->ptr))
	{
		str = get_str(fd, 0);
		if (str)
		{
			if (!node->str)
			{
				node->str = str;
				node->ptr = str;
			}
			else
			{
				node->ptr = ft_strjoin(node->ptr, str);
				free(node->str);
				free(str);
				node->str = node->ptr;
			}
		}
	}
	len_line = get_len_line(node->ptr);
	line = ft_substr(node->ptr, 0, len_line);
	node->ptr += len_line + 1;
	if (!(*node->ptr))
		free(node->str);
	return (line);
}

char	*get_str(int fd, size_t len_total)
{
	char	*buf;
	char	*str;
	size_t	len;

	buf = malloc(BUFFER_SIZE + 1);
	len = read(fd, buf, BUFFER_SIZE);
	if (len > 0 && !is_there_nl(buf))
		str = get_str(fd, len_total + len);
	else if (len == 0 && len_total == 0)
		str = 0;
	else
	{
		str = malloc(len_total + len + 1);
		str[len_total + len] = 0;
	}
	if (str)
		ft_memcpy(str + len_total, buf, len);
	free(buf);
	return (str);
}
