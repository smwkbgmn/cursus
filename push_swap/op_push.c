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

void	push(t_stack **pushed, t_stack **poped)
{
	t_stack	*temp;

	temp = *poped;
	del_node(poped);
	// ft_stkadd_front(pushed, temp);
	ft_stkadd_back(pushed, temp);
	*pushed = (*pushed)->prev;
}

void	del_node(t_stack **stk)
{
	t_stack	*del;

	del = *stk;
	if (del)
	{
		if (del->next == *stk)
			*stk = NULL;
		else
		{
			del->prev->next = del->next;
			del->next->prev = del->prev;
			*stk = (*stk)->next;
		}
	}
}
