/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/25 21:39:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_uint	find_max(t_stack *b, t_uint max);
t_uint	find_next_abv(t_stack *a, t_uint idx_abv, t_uint idx_blw, t_uint chunk, t_uint mid);
t_uint	find_next_blw(t_stack *a, t_uint idx_abv, t_uint idx_blw, t_uint chunk, t_uint mid);

void	sort(t_stack **a, t_stack **b)
{
	t_uint	mid;
	t_uint	cnt_abv;
	t_uint	cnt_blw;
	// t_uint	idx_abv;
	// t_uint	idx_blw;
	// t_uint	chunk_abv;
	// t_uint	chunk_blw;
	t_uint	chunk;
	t_uint	top;

	mid = ft_stksize(*a) / 2;
	// chunk_abv = 1;
	// chunk_blw = 3;
	chunk = 7;
	cnt_abv = 0;
	cnt_blw = 0;
	while (*a)
	{
		top = ref(*a);
		// if (mid <= top && top <= mid + cnt_abv + chunk_abv)
		if (mid <= top && top <= mid + cnt_abv + chunk)
		{
			pb(a, b);
			// if (cnt_abv + chunk_abv != mid)
			if (cnt_abv + chunk != mid)
				cnt_abv++;
			if (ref(*b) < ref((*b)->next))
				sb(*b);
		}
		// else if (mid - cnt_blw - chunk_blw - 1 <= top && top < mid)
		else if (mid - cnt_blw - chunk <= top && top < mid)
		{
			pb(a, b);
			// if (cnt_blw + chunk_blw + 1 < mid)
			if (cnt_blw + chunk < mid)
				cnt_blw++;
			rb(b);
		}
		else
		{
			// idx_abv = find_next_abv(*a, cnt_abv, cnt_blw, chunk, mid);
			// idx_blw = find_next_blw(*a, cnt_abv, cnt_blw, chunk, mid);
			// if (idx_abv <= idx_blw)
			// 	while (idx_abv-- > 0)
			// 		ra(a);
			// else
			// 	while (idx_blw-- > 0)
			// 		rra(a);
			ra(a);
		}
	}

	t_uint	idx_move;
	t_uint	size;

	size = ft_stksize(*b);
	while (*b)
	{
		idx_move = find_max(*b, size - 1);
		if (idx_move < size / 2)
			while (idx_move-- > 0)
				rb(b);
		else
			while (size - idx_move++ > 0)
				rrb(b);
		pa(a, b);
		size--;
	}
}

t_uint	find_next_abv(t_stack *a, t_uint cnt_abv, t_uint cnt_blw, t_uint chunk, t_uint mid)
{
	t_stack	*stk;
	t_uint	idx_abv;
	t_uint	idx_blw;
	t_uint	top;

	stk = a->next;
	idx_abv = 1;
	while (stk != a)
	{
		top = ref(stk);
		// printf("abv abv : top --- %d\tidx_abv --- %d\n", top, idx_abv);
		// if (mid <= top && top <= mid + cnt_abv + chunk)
		// 	break ;
		// else if (mid - cnt_blw - chunk <= top && top < mid)
		// 	break ;
		if (mid <= top && top <= mid + cnt_abv + chunk)
			break ;
		else
		{
			idx_abv++;
			stk = stk->next;
		}
	}

	stk = a->next;
	idx_blw = 1;
	while (stk != a)
	{
		top = ref(stk);
		// printf("abv blw : top --- %d\tidx_blw --- %d\n", top, idx_blw);
		if (mid - cnt_blw - chunk - 1 <= top && top < mid)
			break ;
		else
		{
			idx_blw++;
			stk = stk->next;
		}
	}
	if (idx_abv < idx_blw)
		return (idx_abv);
	else
		return (idx_blw);
}

t_uint	find_next_blw(t_stack *a, t_uint cnt_abv, t_uint cnt_blw, t_uint chunk, t_uint mid)
{
	t_stack	*stk;
	t_uint	idx_abv;
	t_uint	idx_blw;
	t_uint	top;

	mid = 50;

	stk = a->prev;
	idx_abv = 1;
	while (stk != a)
	{
		top = ref(stk);
		// printf("blw abv : top --- %d\tidx_abv --- %d\n", top, idx_abv);
		// if (mid <= top && top <= mid + cnt_abv + chunk)
		// 	break ;
		// else if (mid - cnt_blw - chunk <= top && top < mid)
		// 	break ;
		if (mid <= top && top <= mid + cnt_abv + chunk)
			break ;
		else
		{
			idx_abv++;
			stk = stk->prev;
		}
	}

	stk = a->prev;
	idx_blw = 1;
	while (stk != a)
	{
		top = ref(stk);
		// printf("blw blw : top --- %d\tidx_blw --- %d\n", top, idx_blw);
		if (mid - cnt_blw - chunk - 1 <= top && top < mid)
			break ;
		else
		{
			idx_blw++;
			stk = stk->prev;
		}
	}
	if (idx_abv < idx_blw)
		return (idx_abv);
	else
		return (idx_blw);
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
