/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:50:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/03 02:20:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* example
5 2 4 3 1


*/

#include "push_swap.h"

static t_bool	is_sorted(t_stack *a, t_uint size);

void	sort_5(t_stack **a, t_stack **b)
{
	t_uint	size;
	t_uint	idx;

	size = ft_stksize(*a);
	if (*b)
		return ;
	while (!is_sorted(*a, size))
	{
		idx = 0;
		while (idx++ < size)
		{
			test_print_stack(*a, *b);
			if (ref(*a) > ref((*a)->next))
				sa(*a);
			else
				ra(a);
		}
		test_print_stack(*a, *b);
	}
	// while (ref(*a) != 0)
	// 	ra(a);
}

static t_bool	is_sorted(t_stack *a, t_uint size)
{
	t_uint	cnt_disorder;

	size = ft_stksize(a);
	cnt_disorder = 0;
	while (size-- > 0)
	{
		if (ref(a) > ref(a->next))
		{
			cnt_disorder++;
			if (cnt_disorder > 1)
				return (FALSE);
		}
		a = a->next;
	}
	return (TRUE);
}
