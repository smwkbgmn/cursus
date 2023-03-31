/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:16:56 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 16:22:58 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotate(t_list **head);

void	ra(t_list **a)
{
	set_rotate(a);
	printf("ra\n");
}

void	rb(t_list **b)
{
	set_rotate(b);
	printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

void	set_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *head;
	tail = ft_lstlast(*head);
	*head = tmp->next;
	tmp->next = NULL;
	tail->next = tmp;
}
