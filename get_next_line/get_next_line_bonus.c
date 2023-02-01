/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:15:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/02 05:16:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Consider standard input (fd 1)
// Read buf size will be modified during evaluation
// compiler buf size flag : -D BUFFER_SIZE=n

#include <stdio.h>

#include "get_next_line.h"

char	*read_line(t_list *node, int fd);
char	*get_str(int fd, size_t len_total);
void	adjust(t_list *node, char *new, size_t len_p, size_t len_n);
void	ft_lstdel(t_list **head, int fd);

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*line;

	line = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		node = init_list(&head, fd);
		if (node)
		{
			if (!node->ptr)
				set_str(node, get_str(fd, 0));
			line = read_line(node, fd);
			if (!line)
				ft_lstdel(&head, fd);
		}
	}
	return (line);
}

char	*read_line(t_list *node, int fd)
{
	char	*line;
	char	*new;
	size_t	len_p;
	size_t	len_n;

	line = NULL;
	if (node->ptr)
	{
		// printf("you may not enter here\n");
		len_p = get_len(node->ptr);
		if (!ft_strchr(node->ptr, '\n'))
			new = get_str(fd, 0);
		else
			new = NULL;
		len_n = get_len(new);
		if (len_p > 0 || len_n > 0)
		{
			line = malloc(len_p + len_n + 1);
			ft_strncpy(line, node->ptr, len_p);
			ft_strncpy(line + len_p, new, len_n);
		}
		adjust(node, new, len_p, len_n);
	}
	return (line);
}

char	*get_str(int fd, size_t len_total)
{
	char	*buf;
	char	*str;
	ssize_t	len;

	buf = malloc(BUFFER_SIZE + 1);
	len = read(fd, buf, BUFFER_SIZE);
	if ((len == 0 && len_total == 0) || len == ERROR)
		str = NULL;
	else if (len > 0 && !ft_strchr(buf, '\n'))
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

void	adjust(t_list *node, char *new, size_t len_p, size_t len_n)
{
	if (new)
	{
		set_str(node, new);
		node->ptr += len_n;
	}
	else
	{
		node->ptr += len_p;
		if (*node->ptr == 0)
			set_str(node, NULL);
	}	
}

void	ft_lstdel(t_list **head, int fd)
{
	t_list	*node;
	t_list	*node_del;

	node = *head;
	if (node->fd == fd)
	{
		*head = node->next;
		free(node);
	}
	else
	{
		while (node->next->fd != fd)
			node = node->next;
		node_del = node->next;
		node->next = node_del->next;
		free(node_del);
	}
}
