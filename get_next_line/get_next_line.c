/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/31 04:43:22 by donghyu2         ###   ########.fr       */
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

	if (!node)
		node = init_list(fd);
	line = read_line(node, fd);
	if (!line)
		free(node);
	return (line);
}

char	*read_line(t_list *node, int fd)
{
	char	*new;
	char	*line;
	size_t	len_ptr;
	size_t	len_new;

	new = NULL;
	if (!node->ptr || !is_there_nl(node->ptr))
		new = get_str(fd, 0);
	printf("new[%s]\n", new);
	len_ptr = get_len(node->ptr);
	len_new = get_len(new);
	if (len_ptr > 0 || len_new > 0)
	{
		line = malloc(len_ptr + len_new + 1);
		line[len_ptr + len_new] = 0;
		if (line)
		{
			ft_strncpy(line, node->ptr, len_ptr);
			ft_strncpy(line + len_ptr, new, len_new);
		}
		if (!node->ptr || !is_there_nl(node->ptr))
		{
			set_new_str(node, new);
			node->ptr += len_new;
		}
		else
			node->ptr += len_ptr;
		if (*node->ptr == 0)
			set_new_str(node, NULL);
	}
	else
		line = NULL;
	return (line);
}

char	*get_str(int fd, size_t len_total)
{
	char	*buf;
	char	*str;
	size_t	len;

	buf = malloc(BUFFER_SIZE + 1);
	len = read(fd, buf, BUFFER_SIZE);
	if (len == 0 && len_total == 0)
		str = NULL;
	else if (len > 0 && !is_there_nl(buf))
		str = get_str(fd, len_total + len);
	else
	{
		str = malloc(len_total + len + 1);
		str[len_total + len] = 0;
	}
	if (str)
		ft_strncpy(str + len_total, buf, len);
	free(buf);
	return (str);
}
