/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:50:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 20:02:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_max_mid(t_stack *a, t_uint *max, t_uint *mid);

void	sort_3(t_stack **a, t_stack **b)
{
	t_uint	max;
	t_uint	mid;

	if (b)
	{
		if (ft_stksize(*a) == 2)
		{
			if (ref(*a) > ref((*a)->next))
				sa(*a);
		}
		else
		{
			set_max_mid(*a, &max, &mid);
			if (ref(*a) == max)
				ra(a);
			else if (ref((*a)->next) == max)
				rra(a);
			if (ref(*a) == mid)
				sa(*a);
		}
	}
}

static void	set_max_mid(t_stack *a, t_uint *max, t_uint *mid)
{
	t_uint	size;
	t_uint	top;

	size = 3;
	while (size-- > 0)
	{
		top = ref(a);
		if (top > ref(a->prev) && top > ref(a->next))
			*max = top;
		else if ((top > ref(a->prev) && top < ref(a->next))
			|| (top < ref(a->prev) && top > ref(a->next)))
			*mid = top;
		a = a->next;
	}
}
