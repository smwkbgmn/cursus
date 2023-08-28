/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:08:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 02:18:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

t_list	*ft_lstnew(t_thread *thread_new, t_vars *prgm)
{
	t_list	*list_new;

	list_new = malloc(sizeof(t_list));
	list_new->thread = thread_new;
	list_new->program = prgm;
	list_new->next = list_new;
	list_new->prev = list_new;
	return (list_new);
}

void	ft_lstadd(t_list **list, t_list *new)
{
	t_list	*head;
	t_list	*tail;

	if (*list)
	{
		head = *list;
		tail = (*list)->prev;
		tail->next = new;
		new->next = head;
		new->prev = tail;
		head->prev = new;
	}
	else
		*list = new;
}

// ft_lstclear