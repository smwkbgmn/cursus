/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hourglass1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 18:30:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_to_b(t_stack **a, t_stack **b);
static t_uint	get_chunk(t_uint size);
static void		check_swap(t_stack **a, t_stack **b);
static void		push_to_b(t_stack **a, t_stack **b, t_uint idx, t_uint chunk);
void			sort_to_a(t_stack **a, t_stack **b);

void	sort_hourglass(t_stack **a, t_stack **b)
{
	sort_to_b(a, b);
	sort_to_a(a, b);
}

static void	sort_to_b(t_stack **a, t_stack **b)
{
	t_uint	idx;
	t_uint	chunk;

	idx = 0;
	chunk = get_chunk(ft_stksize(*a));
	while (*a)
	{
		check_swap(a, b);
		if (ref(*a) <= idx + chunk)
		{
			push_to_b(a, b, idx, chunk);
			idx++;
		}
		else
		{
			if (ref((*a)->next) <= idx + chunk && ref(*a) <= idx + chunk + 1)
				sa(*a);
			else
				ra(a);
		}
	}
}

static void	push_to_b(t_stack **a, t_stack **b, t_uint idx, t_uint chunk)
{
	t_uint	top;

	top = ref(*a);
	if (top <= idx + chunk)
	{
		pb(a, b);
		if (top > idx)
		{
			if (top > idx + chunk + 1)
				rr(a, b);
			else
				rb(b);
		}
	}
}

static t_uint	get_chunk(t_uint size)
{
	t_uint	cnt_fifty;

	cnt_fifty = size / 50;
	return (14 + (cnt_fifty * 2)
		+ (1 * (cnt_fifty > 0 && cnt_fifty % 4 == 0)));
}

static void	check_swap(t_stack **a, t_stack **b)
{
	if (*b && ref(*b) < ref((*b)->next))
	{
		if (*a && (*a)->next && ref(*a) > ref((*a)->next))
			ss(*a, *b);
		else
			sb(*b);
	}
}
