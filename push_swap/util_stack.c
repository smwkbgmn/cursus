/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:10:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/01 23:44:58 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

t_stack	*ft_stknew(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->data = data;
		new->order = 0;
		new->next = new;
		new->prev = new;
	}
	return (new);
}

void	ft_stkadd_front(t_stack **stack, t_stack *new)
{
	ft_stkadd_back(stack, new);
	*stack = new;
}

void	ft_stkadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*head;
	t_stack	*tail;

	if (*stack == NULL)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		head = *stack;
		tail = head->prev;
		head->prev = new;
		tail->next = new;
		new->next = head;
		new->prev = tail;
	}
}

// t_stack	*ft_stkidx(t_stack *stack, int idx)
// {
// 	int	size;

// 	size = ft_stksize(stack);
// 	if (-1 * size <= idx && idx < size)
// 	{
// 		idx += size * (idx < 0);
// 		while (idx-- > 0)
// 			stack = stack->next;
// 	}
// 	else
// 		stack = NULL;
// 	return (stack);
// }

t_uint	ft_stksize(t_stack *head)
{
	t_stack	*stack;
	t_uint	len;

	stack = head;
	len = 0;
	if (stack)
	{
		while (stack->next != head)
		{
			stack = stack->next;
			len++;
		}
		len++;
	}
	return (len);
}

void	ft_stkclear(t_stack *stk)
{
	t_stack	*stk_del;
	t_uint	size;

	size = ft_stksize(stk);
	while (size-- > 0)
	{
		stk_del = stk;
		stk = stk->next;
		free(stk_del);
	}
}

t_uint	ref(t_stack *stk)
{
	if (stk)
		return (stk->order);
	else
		return (0);
}
