/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/04 03:54:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	line = NULL;
	if (fd != ERROR && BUFFER_SIZE > 0)
	{
		node = init_list(&head, fd);
		if (node)
		{
			if (!node->str)
			{
				node->str = get_str(fd, 0);
				node->ptr = node->str;
			}
			line = read_line(node, fd);
			if (!line || !node->str)
				ft_lstdel(&head, fd);
		}
	}
	return (line);
}

char	*read_line(t_list *node, int fd)
{
	char	*line;
	char	*new;
	size_t	len_ptr;
	size_t	len_new;

	line = NULL;
	if (node->ptr && node->ptr != WRONG_FD)
	{
		new = NULL;
		if (!ft_strchr(node->ptr, '\n'))
			new = get_str(fd, 0);
		len_ptr = get_len(node->ptr);
		len_new = get_len(new);
		if (len_ptr + len_new > 0 && new != WRONG_FD)
		{
			line = ft_calloc(len_ptr + len_new + 1, 1);
			if (line)
			{
				ft_strncpy(line, node->ptr, len_ptr);
				ft_strncpy(line + len_ptr, new, len_new);
			}
		}
		adjust(node, new, len_ptr, len_new);
	}
	return (line);
}

char	*get_str(int fd, size_t len_total)
{
	char	*buf;
	char	*new;
	ssize_t	len;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (buf)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == ERROR)
			new = WRONG_FD;
		else if (len == 0 && len_total == 0)
			new = NULL;
		else if (len > 0 && !ft_strchr(buf, '\n'))
			new = get_str(fd, len_total + len);
		else
			new = ft_calloc(len_total + len + 1, 1);
		if (new && new != WRONG_FD)
			ft_strncpy(new + len_total, buf, len);
		free(buf);
		return (new);
	}
	else
		return (NULL);
}

t_list	*init_list(t_list **head, int fd)
{
	t_list	*node;
	t_list	*new;

	node = *head;
	if (node)
	{
		while (node->fd != fd && node->next)
			node = node->next;
		if (node->fd == fd)
			return (node);
	}
	new = malloc(sizeof(t_list));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
		new->ptr = NULL;
		new->next = NULL;
		if (!node)
			*head = new;
		else
			node->next = new;
	}
	return (new);
}

void	ft_lstdel(t_list **head, int fd)
{
	t_list	*node;
	t_list	*node_del;

	node = *head;
	if (node->fd == fd)
	{
		node_del = node;
		*head = node->next;
	}
	else
	{
		while (node->next->fd != fd)
			node = node->next;
		node_del = node->next;
		node->next = node_del->next;
	}
	free(node_del);
}
