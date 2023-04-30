/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/25 17:31:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_asc(t_stack **a, t_stack **b);
t_uint	find_position(t_stack *b, t_uint order, t_uint min, t_uint max);
t_bool	check_condition(t_stack *stk, t_uint order, t_bool sml, t_bool big);

void	sort(t_stack **a, t_stack **b)
{
	push_asc(a, b);
	push_asc(a, b);
	push_asc(a, b);
	push_asc(a, b);
}

void	push_asc(t_stack **a, t_stack **b)
{
	t_uint	size_run;
	t_uint	cnt_push;
	t_uint	min;
	t_uint	max;

	size_run = 16;
	cnt_push = 0;
	min = ref(*a);
	max = ref(*a);

	/* push first descending run */

	while (ref(*a) > ref((*a)->next))
	{
		// if (ref(*a) > ref((*a)->next))
		// 	sa(*a);
		if (ref(*a) < min)
			min = ref(*a);
		if (ref(*a) > max)
			max = ref(*a);
		pb(a, b);
		cnt_push++;
	}

	/* push the rest of data untill the size of stack b meet the minimum run size */

	t_uint	idx_to_move;

	if (cnt_push < size_run)
	{
		while (cnt_push++ < size_run)
		{
			// if (ref(*a) > ref((*a)->next))
			// 	sa(*a);
			idx_to_move = find_position(*b, ref(*a), min, max);
			// printf("result of idx --- %d\n", idx_to_move);
			if (idx_to_move < ft_stksize(*b) / 2)
				while (idx_to_move-- > 0)
					rb(b);
			else
				while (ft_stksize(*b) - idx_to_move++ > 0)
					rrb(b);
			if (ref(*a) < min)
				min = ref(*a);
			if (ref(*a) > max)
				max = ref(*a);
			pb(a, b);
		}
	}

	/* rotate to be sorted before push a */

	idx_to_move = find_position(*b, max + 1, min, max);
	if (idx_to_move < ft_stksize(*b) / 2)
		while (idx_to_move-- > 0)
			rb(b);
	else
		while (ft_stksize(*b) - idx_to_move++ > 0)
			rrb(b);
	while (*b)
	{
		pa(a, b);
		ra(a);
	}
}

t_uint	find_position(t_stack *b, t_uint order, t_uint min, t_uint max)
{
	t_stack	*stk;
	t_uint	idx;

	stk = b;
	idx = 0;
	while (stk)
	{
		// printf("order --- %d\tref(b) --- %d\n", order, ref(stk));
		if (check_condition(stk, order, order < min, order > max))
			break ;
		else
		{
			idx++;
			stk = stk->next;
		}
		if (stk == b)
			break ;
	}
	return (idx);
}

t_bool	check_condition(t_stack *stk, t_uint order, t_bool sml, t_bool big)
{
	if (sml || big)
		return (ref(stk->prev) > ref(stk) && ref(stk) < ref(stk->next));
	else
		return (ref(stk->prev) < order && order < ref(stk));
}
