/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:50:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/10 19:04:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		make_a_be_three(t_stack **a, t_stack **b, t_uint *size);

void	sort_5(t_stack **a, t_stack **b)
{
	t_uint	size;
	t_uint	idx;

	size = ft_stksize(*a);
	make_a_be_three(a, b, &size);
	sort_3(a, b);
	while (*b)
	{
		idx = find_position_asc(*a, size, ref(*b));
		rotate_a_idx(a, size, idx);
		pa(a, b);
		size++;
	}
	idx = find_start(*a);
	rotate_a_idx(a, size, idx);
}

static void	make_a_be_three(t_stack **a, t_stack **b, t_uint *size)
{
	while (*size > 3)
	{
		pb(a, b);
		(*size)--;
	}
}
 