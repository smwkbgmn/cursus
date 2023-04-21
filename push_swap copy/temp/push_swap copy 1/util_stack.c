/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:10:50 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/31 22:07:15 by donghyu2         ###   ########.fr       */
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
		new->next = NULL;
	}
	return (new);
}

void	ft_stkadd_back(t_stack **stack, t_stack *new)
{
	if (*stack)
		ft_stklast(*stack)->next = new;
	else
		*stack = new;
}

t_stack	*ft_stklast(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
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

int	ft_stksize(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
