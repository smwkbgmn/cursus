/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/26 00:17:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Consider standard input (fd 1)
// Read buf size will be modified during evaluation
// compiler buf size flag : -D BUFFER_SIZE=n

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#include <stdio.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*str_new;
	char			*str_read;
	char			*str_return;
	size_t			len_line;

	node = init_node(&head, fd);
	if (!node->str || !check_nl(node->ptr))
	{
		str_read = read_str(fd, 1, 0);
		if (str_read)
		{
			if (!node->str)
				str_new = str_read;
			else
			{
				str_new = strjoin(node->ptr, str_read);
				free(node->str);
				free(str_read);
			}
			node->str = str_new;
			node->ptr = str_new;
		}
	}
	len_line = get_len(&(node->ptr));
	if (
	return (0);
}

size_t	get_len(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '\n' && str[idx])
		idx++;
	return (idx);
}

char	*read_str(int fd, size_t cnt, size_t len_total)
{
	char	*buf;
	char	*str;
	ssize_t	len_rd;

	buf = malloc(BUFFER_SIZE + 1);
	len_rd = read(fd, buf, BUFFER_SIZE);
	if (len_rd > 0 && !check_nl(buf))
		str = read_str(fd, ++cnt, len_total + len_rd);
	else
	{
		if (len_total == 0)
			return (FALSE);
		str = malloc(len_total + len_rd + 1);
		str[len_total] = 0;
	}
	ft_memcpy(str + len_total, buf, len_rd);
	free(buf);
	return (str);
}

short	check_nl(char *str)
{
	while (*str != '\n' && *str)
		str++;
	return (*str == '\n');
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;

	if (n > 0 && dst != src)
	{
		dst_c = (char *)dst;
		src_c = (char *)src;
		while (n > 0)
		{
			*dst_c++ = *src_c++;
			n--;
		}
	}
	return (dst);
}
