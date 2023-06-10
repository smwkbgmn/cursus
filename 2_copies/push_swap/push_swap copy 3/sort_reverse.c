/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:19:03 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 18:30:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_uint	find_position_max(t_stack *a, t_uint size);

void	sort_reverse(t_stack **a, t_stack **b)
{
	t_uint	size;

	size = ft_stksize(*a);
	if (ref(*a) != size - 1)
		rotate_a_idx(a, size, find_position_max(*a, size));
	while (*a)
	{
		rra(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}

static t_uint	find_position_max(t_stack *a, t_uint size)
{
	t_uint	idx;

	idx = 0;
	while (ref(a) != size - 1)
	{
		a = a->next;
		idx++;
	}
	return (idx);
}
