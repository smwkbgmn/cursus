/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/06 21:10:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	t_uint	size;
	int		fst;
	int		sec;
	int		trd;

	size = ft_stksize(*a);
	while (size-- > 0)
	{
		fst = ref(*a, 0);
		sec = ref(*a, 1);
		trd = ref(*a, 2);
		if (fst < sec)
			ra(a);
		else
		{
			if ()
		}
	}
}
