/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 16:12:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"

static char	*read_line(t_fd *node, int fd);
static char	*get_str(int fd, size_t len_total);
static t_fd	*init_node(t_fd **head, int fd);
static void	del_node(t_fd **head, int fd);

char	*get_next_line(int fd)
{
	static t_fd	*head;
	t_fd		*node;
	char		*line;

	line = NULL;
	if (fd != ERROR && BUFFER_SIZE > 0)
	{
		node = init_node(&head, fd);
		if (node)
		{
			if (!node->str)
			{
				node->str = get_str(fd, 0);
				node->ptr = node->str;
			}
			line = read_line(node, fd);
			if (!line)
				del_node(&head, fd);
		}
	}
	return (line);
}

static char	*read_line(t_fd *node, int fd)
{
	char	*line;
	char	*str_new;
	char	*ptr_nl;

	line = NULL;
	if (node->str && *node->str)
	{
		ptr_nl = gnl_strchr(node->ptr, '\n');
		if (!ptr_nl)
			str_new = get_str(fd, 0);
		else
			str_new = NULL;
		if (ptr_nl || str_new)
		{
			line = gnl_strjoin(node->ptr, str_new);
			adjust_node(node, str_new);
		}
	}
	return (line);
}

static char	*get_str(int fd, size_t total)
{
	char	*buf;
	char	*str;
	ssize_t	len;

	str = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len != ERROR)
		{
			buf[len] = '\0';
			if (len > 0 && !gnl_strchr(buf, '\n'))
				str = get_str(fd, total + len);
			else
			{
				str = malloc(total + len + 1);
				if (str)
					str[total + len] = '\0';
			}
			gnl_memcpy(str + total, buf, len * (str != NULL));
		}
		free(buf);
	}
	return (str);
}

static t_fd	*init_node(t_fd **head, int fd)
{
	t_fd	*node;
	t_fd	*new;

	node = *head;
	if (node)
	{
		while (node->fd != fd && node->next)
			node = node->next;
		if (node->fd == fd)
			return (node);
	}
	new = malloc(sizeof(t_fd));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
		new->next = NULL;
		if (!node)
			*head = new;
		else
			node->next = new;
	}
	return (new);
}

static void	del_node(t_fd **head, int fd)
{
	t_fd	*node;
	t_fd	*del;

	node = *head;
	if (node->fd == fd)
	{
		del = node;
		*head = node->next;
	}
	else
	{
		while (node->next->fd != fd)
			node = node->next;
		del = node->next;
		node->next = del->next;
	}
	if (del->str)
		free(del->str);
	free(del);
}
