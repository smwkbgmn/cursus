/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:39:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 00:03:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *head);

void	sa(t_stack *a)
{
	swap(a);
	printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	printf("ss\n");
}

void	swap(t_stack *head)
{
	int	tmp;

	if (head && head->next)
	{
		tmp = head->data;
		head->data = head->next->data;
		head->next->data = tmp;
	}
}
