/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:50:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/03 23:01:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rotate(t_stack **a, t_stack **b)
{
	printf("rotate\n");
	if (b)
		rotate_a_idx(a, ft_stksize(*a), find_start((*a)));
}
