/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:04:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 18:37:30 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint			get_cnt_disorder(t_stack *a, t_uint size);
static t_uint	set_stack_a(t_stack **a);
static void		push_to_b(t_stack **a, t_stack **b, t_uint *order);
static void		push_to_a(t_stack **a, t_stack **b, t_uint order);

void	sort_insertion(t_stack **a, t_stack **b)
{
	t_uint	order;

	order = 0;
	push_to_b(a, b, &order);
	push_to_a(a, b, order);
}

static void	push_to_b(t_stack **a, t_stack **b, t_uint *order)
{
	t_uint	size;
	t_uint	cnt;
	t_uint	idx;

	size = 0;
	cnt = set_stack_a(a);
	while (size < cnt)
	{
		if (ref(*a) != *order)
		{
			idx = find_position_dsc(*b, size, ref(*a));
			rotate_b_idx(b, size, idx);
			pb(a, b);
			size++;
		}
		else
			ra(a);
		(*order)++;
	}
}

static t_uint	set_stack_a(t_stack **a)
{
	t_uint	size;

	size = ft_stksize(*a);
	rotate_a_idx(a, size, find_start(*a));
	return (get_cnt_disorder(*a, size));
}

static void	push_to_a(t_stack **a, t_stack **b, t_uint order)
{
	t_uint	size;
	t_uint	idx;

	size = ft_stksize(*b);
	idx = find_position_dsc(*b, size, order);
	rotate_b_idx(b, size, idx);
	while (order > 0)
	{
		if (*b && ref(*b) == order - 1)
			pa(a, b);
		else
			rra(a);
		order--;
	}
}
