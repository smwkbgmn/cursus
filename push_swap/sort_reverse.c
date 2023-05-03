/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:19:03 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/03 23:01:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_reverse(t_stack **a, t_stack **b)
{
	printf("reverse\n");
	while (*a)
	{
		rra(a);
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}
