/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/31 22:52:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*init_list(t_list **head, int fd)
{
	t_list	*node;
	t_list	*new;

	node = *head;
	while (node && node->next && node->fd != fd)
		node = node->next;
	if (!node || node->fd != fd)
	{
		new = malloc(sizeof(t_list));
		if (new)
		{
			new->fd = fd;
			new->str = NULL;
			new->ptr = NULL;
			new->next = NULL;
		}
		if (!node)
			*head = new;
		else
			node->next = new;
		return (new);
	}
	else
		return (node);
}

size_t	get_len(char *str)
{
	size_t	idx;

	if (!str)
		return (0);
	else
	{
		idx = 0;
		while (str[idx] != '\n' && str[idx])
			idx++;
		return (idx + (str[idx] == '\n'));
	}
}

void	ft_strncpy(char *dst, char *src, size_t n)
{
	while (n > 0 && *src)
	{
		*dst++ = *src++;
		n--;
	}
}

void	set_str(t_list *node, char *new)
{
	if (node->str)
		free(node->str);
	node->str = new;
	node->ptr = new;
}

char	*ft_strchr(char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

