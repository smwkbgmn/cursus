/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:00:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/03 22:58:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	find_start(t_stack *a)
{
	t_uint	idx;

	idx = 0;
	while (ref(a) != 0)
	{
		idx++;
		a = a->next;
	}
	return (idx);
}

t_uint	find_position_asc(t_stack *stk, t_uint size, t_uint order)
{
	t_uint	idx;

	idx = 0;
	while (idx < size && (order > ref(stk) || order < ref(stk->prev)))
	{
		idx++;
		stk = stk->next;
	}
	if (idx == size && size > 0)
	{
		idx = 0;
		while (ref(stk) > ref(stk->prev))
		{
			idx++;
			stk = stk->next;
		}
	}
	return (idx);
}

t_uint	find_position_dsc(t_stack *stk, t_uint size, t_uint order)
{
	t_uint	idx;

	idx = 0;
	while (idx < size && (order < ref(stk) || order > ref(stk->prev)))
	{
		idx++;
		stk = stk->next;
	}
	if (idx == size && size > 0)
	{
		idx = 0;
		while (ref(stk) < ref(stk->prev))
		{
			idx++;
			stk = stk->next;
		}
	}
	return (idx);
}

void	rotate_a_idx(t_stack **a, t_uint size, t_uint idx)
{
	if (idx <= size / 2)
		while (idx-- > 0)
			ra(a);
	else
		while (size - idx++ > 0)
			rra(a);
}

void	rotate_b_idx(t_stack **b, t_uint size, t_uint idx)
{
	if (idx <= size / 2)
		while (idx-- > 0)
			rb(b);
	else
		while (size - idx++ > 0)
			rrb(b);
}
