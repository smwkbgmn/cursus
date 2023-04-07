/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/07 16:10:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	t_uint	size;
	int		crnt;
	int		prev;
	int		next;

	size = ft_stksize(*a);
	while (size-- > 0)
	{
		while (ref(*a, 0) < ref(*a, 1))
			ra(*a);
		crnt = ref(*a, 0);
		prev = ref(*a, -1);
		next = ref(*a, 1);
		else
		{
			if (next > ref(*a, 2))
				
		}
	}
}
