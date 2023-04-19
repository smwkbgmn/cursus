/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/19 23:41:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b, int chunk, int i);
void	b_to_a(t_stack **a, t_stack **b);

void	sort(t_stack **a, t_stack **b)
{
	a_to_b(a, b, 1, 0);
	b_to_a(a, b);
}

void	a_to_b(t_stack **a, t_stack **b, int chunk, int i)
{
	// int	length;

	// length = a->length - 1;
	// length = ft_stksize(*a);
	// while (a->length != 0)
	while (*a)
	{
		if (ref(*a, 0) <= i)
		{
			pb(a, b);
			i++;
		}
		else if (ref(*a, 0) > i && ref(*a, 0) <= i + chunk)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (ref(*a, 0) > (i + chunk))
		{
			if (i < (int)ft_stksize(*a) / 2 && i >= 0)
				rra(a);
			else
				ra(a);
		}
		// length--;
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	// int	length;

	// length = b->length - 1;
	// while (b->length != 0)
	while (*b)
	{
		// sort_b(b, length);
		pa(a, b);
		// length--;
	}
}

// void	sort_b(t_stack **b)
// {
	
// }
