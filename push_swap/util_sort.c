/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/18 19:35:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push all to stack_b
void	push_to_stack_b(t_stack **a, t_stack **b);
t_stack	*find_stk_to_push(t_stack *a, int chunk, t_bool *direction);
void	rotate_until_min(t_stack **b, int min);
int		find_min(t_stack *b);

// push all to stack_a
void	push_to_stack_a(t_stack **a, t_stack **b);
void	rotate_until_max(t_stack **b, int max);
int		find_max(t_stack *b);

void	sort(t_stack **a, t_stack **b)
{
	push_to_stack_b(a, b);
	push_to_stack_a(a, b);
}

void	push_to_stack_b(t_stack **a, t_stack **b)
{
	int		chunk[5] = {20, 40, 60, 80, 100};
	t_uint	idx;
	t_bool	direction;
	t_stack	*stk_to_push;

	idx = 0;
	while (idx < 5)
	{
		if (idx < 4)
		{
			while (TRUE)
			{
				stk_to_push = find_stk_to_push(*a, chunk[idx], &direction);
				if (stk_to_push)
				{
					while (ref(*a, 0) != ref(stk_to_push, 0))
					{
						if (direction)
							ra(a);
						else
							rra(a);
					}
					rotate_until_min(b, find_min(*b));
					pb(a, b);
					// rb(b);
				}
				else
					break ;
			}
		}
		else
		{
			while (*a)
			{
				rotate_until_min(b, find_min(*b));
				pb(a, b);
			}
		}
		// printf ("idx --- [%d]\n", idx);
		// test_print_stack(*a, *b);
		idx++;
	}
}

t_stack	*find_stk_to_push(t_stack *a, int chunk, t_bool *direction)
{
	t_stack	*hold_top;
	t_stack	*hold_btm;
	t_uint	idx_top;
	t_uint	idx_btm;
	t_uint	mid;

	mid = ft_stksize(a) / 2;

	hold_top = a;
	idx_top = 0;
	while (idx_top < mid)
	{
		if (ref(hold_top, 0) < chunk)
			break ;
		else
		{
			hold_top = hold_top->next;
			idx_top++;
		}
	}

	hold_btm = a->prev;
	idx_btm = 0;
	while (idx_btm < mid)
	{
		if (ref(hold_btm, 0) < chunk)
			break ;
		else
		{
			hold_btm = hold_btm->next;
			idx_btm++;
		}
	}

	// if (idx_top < idx_btm || (idx_top == idx_btm && idx_top != mid))
	if (idx_top < idx_btm)
	{
		*direction = TRUE;
		return (hold_top);
	}
	else if (idx_top > idx_btm)
	{
		*direction = FALSE;
		return (hold_btm);
	}
	else
		return (NULL);
}

void	rotate_until_min(t_stack **b, int min)
{
	while (ref(*b, 0) != min)
		rb(b);
}

// void	rotate_until_min(t_stack **b, int min)
// {
// 	t_stack	*stk;
// 	t_uint	mid;
// 	t_uint	idx;

// 	stk = *b;
// 	idx = 0;
// 	while (stk && stk->next != *b)
// 	{
// 		if (ref(stk, 0) == min)
// 			break ;
// 		else
// 		{
// 			stk = stk->next;
// 			idx++;
// 		}
// 	}
// 	mid = ft_stksize(*b) / 2;
// 	if (idx < mid)
// 	{
// 		while (idx-- > 0)
// 			rb(b);
// 	}
// 	else
// 	{
// 		idx = ft_stksize(*b) - idx;
// 		while (idx-- > 0)
// 			rrb(b);
// 	}
// }

int	find_min(t_stack *b)
{
	t_stack	*stk;
	int		min;

	if (b && b->next)
	{
		stk = b;
		min = ref(b, 0);
		while (stk->next != b)
		{
			if (ref(stk, 0) < min)
				min = ref(stk, 0);
			stk = stk->next;
		}
	}
	else if (b)
		min = ref(b, 0);
	else
		min = 0;
	return (min);
}

void	push_to_stack_a(t_stack **a, t_stack **b)
{
	// printf ("in push_to_stack_a\n");
	while (*b)
	{
		rotate_until_max(b, find_max(*b));
		pa(a, b);
	}
}

void	rotate_until_max(t_stack **b, int max)
{
	t_stack	*stk;
	t_uint	mid;
	t_uint	idx;

	stk = *b;
	idx = 0;
	while (stk->next != *b)
	{
		if (ref(stk, 0) == max)
			break ;
		else
		{
			stk = stk->next;
			idx++;
		}
	}
	mid = ft_stksize(*b) / 2;
	if (idx < mid)
	{
		while (idx-- > 0)
			rb(b);
	}
	else
	{
		idx = ft_stksize(*b) - idx;
		while (idx-- > 0)
			rrb(b);
	}
}

int	find_max(t_stack *b)
{
	t_stack	*stk;
	int		max;

	if (b && b->next)
	{
		stk = b;
		max = ref(b, 0);
		stk = stk->next;
		while (stk != b)
		{
			if (ref(stk, 0) > max)
				max = ref(stk, 0);
			stk = stk->next;
		}
	}
	else if (b)
		max = ref(b, 0);
	else
		max = 0;
	return (max);
}
