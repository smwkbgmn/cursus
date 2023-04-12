/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/12 19:06:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	t_uint	size;

	*b = NULL;
	size = ft_stksize(*a);
	while (*a && size-- > 0)
	{
		if (ref(*a, 0) < ref(*a, 1))
			ra(a);
		else
		{
			if (ref(*a, -1) < ref(*a, 1))
			{
				sa(*a);
			}
			else
				pb(a, b);
		}	
		test_print_stack(*a, *b);
	}
}
