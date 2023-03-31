/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:15:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 00:02:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

void	push(t_list **head, void *data);
void	del_node(t_list **head);

void	pa(t_list **a, t_list **b)
{
	if (*b != NULL)
	{
		push(a, (*b)->content);
		del_node(b);
	}
	printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	if (*a != NULL)
	{
		push(b, (*a)->content);
		del_node(a);
	}
	printf("pb\n");
}

void	push(t_list **head, void *data)
{
	t_list	*new;

	new = ft_lstnew(data);
	new->next = *head;
	*head = new;
}

void	del_node(t_list **head)
{
	t_list	*del;

	del = *head;
	*head = del->next;
	free(del);
}
