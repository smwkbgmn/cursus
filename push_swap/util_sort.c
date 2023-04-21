/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/21 19:10:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a, t_stack **b);
void	sort_4_a(t_stack **a, t_stack **b);
void	sort_4_b(t_stack **a, t_stack **b);
void	sort_8_a(t_stack **a, t_stack **b);
void	sort_8_b(t_stack **a, t_stack **b);
void	sort_16(t_stack **a, t_stack **b);
t_bool	disorder(t_stack *stk);

void	sort(t_stack **a, t_stack **b)
{
	t_uint	idx;

	sort_2(a, b);

	idx = 0;
	while (idx < 20)
	{
		// printf("4 loop --- %d\n", idx / 4);
		if ((20 - idx) / 2 >= 4 && (idx / 4) % 2 == 0)
			sort_4_a(a, b);
		else
			sort_4_b(a, b);
		idx += 4;
	}

	idx = 0;
	while (idx < 20)
	{
		// printf("8 loop --- %d\n", idx / 8);
		if (20 - idx >= 8)
		{
			if ((idx / 8) % 2 == 0)
				sort_8_a(a, b);
			else
				sort_8_b(a, b);
			idx += 8;
		}
		else
		{
			// if (ft_stksize(*a) > ft_stksize(*b))
			// 	while (idx++ < 20)
			// 		ra(a);
			// else
			// 	while (idx++ < 20)
			// 		rb(b);
			rb(b);
			idx++;
		}
	}

	// sort_16(a, b);
}

void	sort_16(t_stack **a, t_stack **b)
{
	t_uint	cnt_loop;
	t_uint	cnt_push;

	cnt_loop = 16;
	cnt_push = 8;
	while (cnt_loop > 0)
	{
		// printf ("loop --- %d, push --- %d\n", cnt_loop, cnt_push);
		if ((top(*a) > top(*b) || cnt_loop == 1) && cnt_push > 0)
		{
			pa(a, b);
			cnt_push--;
		}
		ra(a);
		cnt_loop--;
	}
}

void	sort_8_a(t_stack **a, t_stack **b)
{
	t_uint	cnt_loop;
	t_uint	cnt_push;

	cnt_loop = 8;
	cnt_push = 4;
	while (cnt_loop > 0)
	{
		if ((top(*a) > top(*b) || cnt_loop == 1) && cnt_push > 0)
		{
			pa(a, b);
			cnt_push--;
		}
		ra(a);
		cnt_loop--;
	}
}

void	sort_8_b(t_stack **a, t_stack **b)
{
	t_uint	cnt_loop;
	t_uint	cnt_push;

	cnt_loop = 8;
	cnt_push = 4;
	while (cnt_loop > 0)
	{
		if ((top(*a) < top(*b) || cnt_loop == 1) && cnt_push > 0)
		{
			pb(a, b);
			cnt_push--;
		}
		rb(b);
		cnt_loop--;
	}
}

void	sort_4_a(t_stack **a, t_stack **b)
{
	t_uint	cnt_loop;
	t_uint	cnt_push;

	cnt_loop = 4;
	cnt_push = 2;
	while (cnt_loop > 0)
	{
		if ((top(*a) > top(*b) || cnt_loop == 1) && cnt_push > 0)
		{
			pa(a, b);
			cnt_push--;
		}
		ra(a);
		cnt_loop--;
	}
}

void	sort_4_b(t_stack **a, t_stack **b)
{
	t_uint	cnt_loop;
	t_uint	cnt_push;

	cnt_loop = 4;
	cnt_push = 2;
	while (cnt_loop > 0)
	{
		if ((top(*a) < top(*b) || cnt_loop == 1) && cnt_push > 0)
		{
			pb(a, b);
			cnt_push--;
		}
		rb(b);
		cnt_loop--;
	}
}

// void	sort_4(t_stack **a, t_stack **b)
// {
// 	t_uint	cnt_loop;
// 	t_uint	cnt_push;

// 	cnt_loop = 4;
// 	cnt_push = 2;
// 	while (cnt_loop > 0)
// 	{
// 		if ((top(*a) > top(*b) || cnt_loop == 1) && cnt_push > 0)
// 		{
// 			pa(a, b);
// 			cnt_push--;
// 		}
// 		ra(a);
// 		cnt_loop--;
// 	}
// }

void	sort_2(t_stack **a, t_stack **b)
{
	t_uint	size;
	t_uint	idx;

	size = ft_stksize(*a);
	idx = 0;
	while (idx < size)
	{
		pb(a, b);
		pb(a, b);
		if (disorder(*a) && disorder(*b))
			ss(*a, *b);
		else if (disorder(*a))
			sa(*a);
		else if (disorder(*b))
			sb(*b);
		rr(a, b);
		rr(a, b);
		idx += 4;
	}
}

t_bool	disorder(t_stack *stk)
{
	return (ref(stk, 0) > ref(stk, 1));
}
