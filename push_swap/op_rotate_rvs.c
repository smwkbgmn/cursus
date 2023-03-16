/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate_rvs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:16:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 16:23:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate_rvs(t_list **head);

void	rra(t_list **a)
{
	set_rotate_rvs(a);
	printf("rra\n");
}

void	rrb(t_list **b)
{
	set_rotate_rvs(b);
	printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}

void	set_rotate_rvs(t_list **head)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = ft_lstidx(*head, -2);
	tail = ft_lstlast(*head);
	tmp->next = NULL;
	tail->next = *head;
	*head = tail;
}
