/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/21 15:23:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack **a, t_stack **b, int chunk);
void	b_to_a(t_stack **a, t_stack **b ,int chunk);
t_uint	find_max(t_stack *b, int chunk, t_uint size);

void	sort(t_stack **a, t_stack **b)
{
	int	chunk;

	chunk = 8;
	a_to_b(a, b, chunk);
	b_to_a(a, b, chunk);
}

void	a_to_b(t_stack **a, t_stack **b, int chunk)
{
	int	idx;
	int	num;

	idx = 0;
	while (*a)
	{
		if (ref(*b, 0) < ref(*b, 1))
			sb(*b);
		num = ref(*a, 0);
		if (num <= idx)
		{
			pb(a, b);
			idx++;
		}
		else if (num <= idx + chunk)
		{
			pb(a, b);
			if (ref(*a, 0) > idx + chunk + 1)
				rr(a, b);
			else
				rb(b);
			idx++;
		}
		// else if (num < idx + (chunk * 2))
		// 	pb(a, b);
		else
			ra(a);
	}
}

// void	a_to_b(t_stack **a, t_stack **b, int chunk)
// {
// 	int	idx;
// 	int	num;

// 	idx = 0;
// 	while (*a)
// 	{
// 		num = ref(*a, 0);
// 		if (num <= idx)
// 		{
// 			pb(a, b);
// 			idx++;
// 		}
// 		else if (idx < num && num <= idx + chunk)
// 		{
// 			pb(a, b);
// 			if (ref(*a, 0) > idx + chunk + 1)
// 				rr(a, b);
// 			else
// 				rb(b);
// 			idx++;
// 		}
// 		else
// 			ra(a);
// 	}
// }

void	b_to_a(t_stack **a, t_stack **b, int chunk)
{
	t_uint	idx_to_move;
	t_uint	size;

	while (*b)
	{
		size = ft_stksize(*b);
		idx_to_move = find_max(*b, chunk, size);
		if (idx_to_move < size / 2)
		{
			while (idx_to_move-- > 0)
				rb(b);
		}
		else
		{
			idx_to_move = size - idx_to_move;
			while (idx_to_move-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

t_uint	find_max(t_stack *b, int chunk, t_uint size)
{
	t_stack	*stk;
	t_uint	idx;

	stk = b;
	idx = 0;
	while (stk->next != b && ref(stk, 0) != (int)size - 1)
	{
		if (idx == (t_uint)chunk && size > (t_uint)chunk * 2)
		{
			idx = size - chunk;
			stk = ft_stkidx(b, chunk * -1);
		}
		else
		{
			idx++;
			stk = stk->next;
		}
	}
	return (idx);
}
