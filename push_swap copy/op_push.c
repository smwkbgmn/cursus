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

#include "push_swap.h"

void	push(t_stack **push, t_stack **pop);
void	del_node(t_stack **head);

void	pa(t_stack **a, t_stack **b)
{
	if (*b != NULL)
		push(a, b);
	printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a != NULL)
		push(b, a);
	printf("pb\n");
}

void	push(t_stack **push, t_stack **pop)
{
	t_stack	*stk_move;

	stk_move = *pop;
	del_node(pop);
	ft_stkadd_front(push, stk_move);
}

void	del_node(t_stack **head)
{
	t_stack	*del;

	del = *head;
	if (del)
	{
		if (del->next == *head)
			*head = NULL;
		else
		{
			del->prev->next = del->next;
			del->next->prev = del->prev;
			*head = (*head)->next;
		}
	}
}
