/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:39:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/27 07:11:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *ptr1, int *ptr2);

void	sa(t_que *a)
{
	swap(ptr(a, a->top), ptr(a, a->top + 1));
	printf("operation [sa]\n");
}

void	sb(t_que *b)
{
	swap(ptr(b, b->top), ptr(b, b->top + 1));
	printf("operation [sb]\n");
}

void	ss(t_que *a, t_que *b)
{
	sa(a);
	sb(b);
	printf("operation [ss]\n");
}

void	swap(int *ptr1, int *ptr2)
{
	int	tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
