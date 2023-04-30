/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/27 15:24:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b);
void	check_swap(t_stack **b);
// void	b_to_a(t_stack **a, t_stack **b, int chunk);
// t_uint	find_max(t_stack *b, t_uint chunk, t_uint size);
void	b_to_a(t_stack **a, t_stack **b);
t_uint	find_max(t_stack *b, t_uint max);

void	sort(t_stack **a, t_stack **b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}

void	a_to_b(t_stack **a, t_stack **b)
{
	t_uint	chunk;
	t_uint	idx;
	t_uint	top;

	chunk = 25;
	// chunk = 15;
	idx = 0;
	while (*a)
	{
		check_swap(b);
		top = ref(*a);
		if (top <= idx)
		{
			pb(a, b);
			idx++;
		}
		else if (top <= idx + chunk)
		{
			pb(a, b);
			idx++;
			if (ref(*a) > idx + chunk)
				rr(a, b);
			else
				rb(b);
		}
		else
			ra(a);
	}
}

void	check_swap(t_stack **b)
{
	if (*b && ref(*b) < ref((*b)->next))
		sb(*b);
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_uint	size;
	t_uint	max;
	t_uint	max_next;
	t_uint	idx;

	t_uint	cnt;
	t_uint	cnt_tmp;

	// while (*b)
	// {
	// 	size = ft_stksize(*b);
	// 	max = size - 1;
	// 	idx = find_max(*b, max);
	// 	if (idx < size / 2)
	// 		while (idx-- > 0)
	// 			rb(b);
	// 	else
	// 		while (size - idx++ > 0)
	// 			rrb(b);
	// 	pa(a, b);
	// }

	while (*b)
	{
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
			// while (size - idx++ > 0)
			// {
			// 	rrb(b);
			// 	if (ref(*b) == max_next - cnt)
			// 	{
			// 		pa(a, b);
			// 		cnt++;
			// 	}
			// }
			while (size - idx++ > 0)
				rrb(b);
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

// void	b_to_a(t_stack **a, t_stack **b)
// {
// 	t_uint	idx_move;
// 	t_uint	size;

// 	size = ft_stksize(*b);
// 	while (*b)
// 			while (idx_move-- > 0)
// 		else
// 			while (size - idx_move++ > 0)
// 				rrb(b);
// 		pa(a, b);
// 		size--;
// 	}
// }

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
