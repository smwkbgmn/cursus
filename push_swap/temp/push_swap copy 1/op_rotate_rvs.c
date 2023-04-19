/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_rvs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:16:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/31 22:06:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_rvs(t_stack **head);

void	rra(t_stack **a)
{
	set_rotate_rvs(a);
	printf("rra\n");
}

void	rrb(t_stack **b)
{
	set_rotate_rvs(b);
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	set_rotate_rvs(a);
	set_rotate_rvs(b);
	printf("rrr\n");
}

void	set_rotate_rvs(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (*head && (*head)->next)
	{
		tmp = ft_stkidx(*head, -2);
		tail = tmp->next;
		tmp->next = NULL;
		tail->next = *head;
		*head = tail;
	}
}
