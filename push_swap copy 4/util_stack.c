/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:10:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/13 15:49:35 by donghyu2         ###   ########.fr       */
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

t_stack	*ft_stkidx(t_stack *stack, int idx)
{
	int	size;

	size = ft_stksize(stack);
	if (-1 * size <= idx && idx < size)
	{
		idx += size * (idx < 0);
		while (idx-- > 0)
			stack = stack->next;
	}
	else
		stack = NULL;
	return (stack);
}

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
