/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:16:56 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 22:09:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_rotate(t_stack **head);

void	ra(t_stack **a)
{
	set_rotate(a);
	printf("ra\n");
}

void	rb(t_stack **b)
{
	set_rotate(b);
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	set_rotate(a);
	set_rotate(b);
	printf("rr\n");
}

static void	set_rotate(t_stack **head)
{
	*head = (*head)->next;
}
