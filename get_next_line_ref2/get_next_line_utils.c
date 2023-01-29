/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/25 02:06:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

static t_list	*lstlast(t_list *head);

t_list	*init_node(t_list **head, int fd)
{
	t_list	*node;

	node = find_node(*head, fd);
	if (!node)
	{
		node = malloc(sizeof(t_list));
		if (node)
		{
			node->next = 0;
			node->fd = fd;
			node->str = 0;
			node->ptr = 0;
			if (*head)
				lstlast(*head)->next = node;
			else
				*head = node;
		}
	}
	return (node);
}

t_list	*find_node(t_list *head, int fd)
{
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	return (FALSE);
}

static t_list	*lstlast(t_list *head)
{
	while (head->next)
		head = head->next;
	return (head);
}
