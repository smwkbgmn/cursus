/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/27 15:03:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b);
void	b_to_a(t_stack **a, t_stack **b);
t_uint	find_max(t_stack *b, t_uint max);

void	sort(t_stack **a, t_stack **b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}

void	a_to_b(t_stack **a, t_stack **b)
{
	t_uint	top;
	t_uint	mid;
	t_uint	cnt_abv = 0;
	t_uint	cnt_blw = 0;
	t_uint	chunk = 15;

	mid = ft_stksize(*a) / 2;
	while (*a)
	{
		if (*b && ref(*b) < ref((*b)->next))
			sb(*b);
		top = ref(*a);
		if (top >= mid && top < mid + cnt_abv + chunk + 1)
		{
			pb(a, b);
			cnt_abv++;
		}
		else if (top < mid && top >= mid - cnt_blw - chunk - 1)
		{
			pb(a, b);
			rb(b);
			if (cnt_blw + chunk + 1 < mid)
				cnt_blw++;
		}
		else
			ra(a);
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_uint	size;
	t_uint	max;
	t_uint	max_next;
	t_uint	idx;

	t_uint	cnt;
	t_uint	cnt_tmp;

	while (*b)
	{
		// test_print_stack(*a, *b);

		if (ref(*b) < ref((*b)->next))
			sb(*b);

		size = ft_stksize(*b);
		max = size - 1;
		if (size > 1)
			max_next = size - 2;
		else
			max_next = 0;
		cnt = 0;

		idx = find_max(*b, max);
		if (idx < size / 2)
		{
			while (idx-- > 0)
			{
				if (ref(*b) == max_next - cnt)
				{
					pa(a, b);
					cnt++;
				}
				else
					rb(b);
			}
		}
		else
		{
			while (size - idx++ > 0)
			{
				rrb(b);
				if (ref(*b) == max_next - cnt)
				{
					pa(a, b);
					cnt++;
				}
			}
			// while (size - idx++ > 0)
			// 	rrb(b);
		}
		cnt_tmp = cnt;
		while (cnt > 0)
		{
			ra(a);
			cnt--;
		}
		pa(a, b);
		cnt = cnt_tmp;
		while (cnt > 0)
		{
			rra(a);
			cnt--;
		}
	}
}

t_uint	find_max(t_stack *b, t_uint max)
{
	t_uint	idx;

	idx = 0;
	while (ref(b) != max)
	{
		idx++;
		b = b->next;
	}
	return (idx);
}
