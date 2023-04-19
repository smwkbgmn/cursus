/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/13 19:48:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ascending_run(t_stack **a, t_stack **b, int size);

void	sort(t_stack **a, t_stack **b)
{
	ascending_run(a, b, ft_stksize(*a));
}

void	ascending_run(t_stack **a, t_stack **b, int size)
{
	while (*a && size-- > 0)
	{
		if (ref(*a, 0) < ref(*a, 1))
		{
			ra(a);
			ra(a);
			size--;
		}
		else
		{
			pb(a, b);
			pb(a, b);
			rrb(b);
			// rrb(b);
			size--;
		}
	}
}

// void	ascending_run(t_stack **a, t_stack **b, int size)
// {
// 	while (*a && size-- > 0)
// 	{
// 		if (ref(*a, 0) < ref(*a, 1))
// 			ra(a);
// 		else
// 		{
// 			if (ref(*a, -1) < ref(*a, 1))
// 			{
// 				sa(*a);
// 				ra(a);
// 				size--;
// 			}
// 			else
// 			{
// 				ra(a);
// 				// pb(a, b);
// 				// if (ref(*a, 0) < ref(*a, 1))
// 				// 	sa(*a);
// 			}
// 		}	
// 		test_print_stack(*a, *b);
// 	}
// }

