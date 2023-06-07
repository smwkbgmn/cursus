/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hourglass1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/07 05:05:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_is_there_idx(t_stack *b, t_uint size, t_uint order);

void	sort_hourglass(t_stack **a, t_stack **b)
{
	t_uint	size_a;
	t_uint	size_b;
	t_uint	idx;

	size_a = ft_stksize(*a);
	size_b = 0;
	idx = 0;
	while (idx < size_a)
	{
		if (check_is_there_idx(*b, size_b, idx))
		{
			while (ref(*b) != idx)
				rb(b);
			pa(a, b);
			ra(a);
			size_b--;
		}
		if (ref(*a) <= idx)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->next && ref(*b) > ref((*b)->next))
				sb(*b);
			size_b++;
		}
		idx++;
	}
}

t_bool	check_is_there_idx(t_stack *b, t_uint size, t_uint order)
{
	while (size-- > 0 && ref(b) != order)
		b = b->next;
	return (ref(b) == order);
}
