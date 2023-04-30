/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:47:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/30 15:58:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		mv_to_max(t_stack **a, t_stack **b, t_uint *size, t_uint *cnt);
static void		set_max(t_uint size, t_uint *max, t_uint *max_next);
static t_uint	get_position_max(t_stack *b, t_uint max);
static void		push_to_a(t_stack **a, t_stack **b, t_uint cnt);

void	sort_to_a(t_stack **a, t_stack **b)
{
	t_uint	size;
	t_uint	cnt;

	size = ft_stksize(*b);
	while (*b)
	{
		cnt = 0;
		mv_to_max(a, b, &size, &cnt);
		push_to_a(a, b, cnt);
		size--;
	}
}

static void	mv_to_max(t_stack **a, t_stack **b, t_uint *size, t_uint *cnt)
{
	t_uint	max;
	t_uint	max_next;
	t_uint	idx;

	set_max(*size, &max, &max_next);
	idx = get_position_max(*b, max);
	if (idx < *size / 2)
	{
		while (idx-- > 0)
		{
			if (ref(*b) == max_next - *cnt)
			{
				pa(a, b);
				(*size)--;
				(*cnt)++;
			}
			else
				rb(b);
		}
	}
	else
		while (*size - idx++ > 0)
			rrb(b);
}

static void	set_max(t_uint size, t_uint *max, t_uint *max_next)
{
	*max = size - 1;
	if (size > 1)
		*max_next = size - 2;
	else
		*max_next = 0;
}

static t_uint	get_position_max(t_stack *b, t_uint max)
{
	t_uint	idx;

	idx = 0;
	while (ref(b) != max)
	{
		idx++;
		b = b->next;
	}
	return (idx);
}

static void	push_to_a(t_stack **a, t_stack **b, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx++ < cnt)
		ra(a);
	pa(a, b);
	idx = 0;
	while (idx++ < cnt)
		rra(a);
}
