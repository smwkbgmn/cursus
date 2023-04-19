/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/01 06:38:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	push(t_stack **a, t_stack **b, int med);
static t_bool	swap(t_stack **a, t_stack **b, t_bool crit_a, t_bool crit_b);
t_bool			chk_null(t_stack *stack);
t_bool	chk_med(t_stack *a, int med);
t_bool	chk_crit_a(t_stack *stack);
t_bool	chk_crit_b(t_stack *stack);
t_bool	chk_sort_a(t_stack *a);
t_bool	chk_sort_b(t_stack *b);

void	sort(t_stack **a, t_stack **b, int med)
{
	int		run;
	t_bool	chk_push;
	t_bool	chk_swap;
	t_bool	crit_a;
	t_bool	crit_b;

	run = 0;
	crit_a = chk_crit_a(*a);
	crit_b = chk_crit_b(*b);

	while ((!crit_a || !crit_b) && run < 100)
	{
		// printf("\n[RUN %d]\n", run++);

		chk_swap = swap(a, b, crit_a, crit_b);
		chk_push = push(a, b, med);

		if (!chk_push && !chk_swap)
		{
			if (!crit_a && crit_b)
				ra(a);
			else if (crit_a && !crit_b)
				rb(b);
			else
				rr(a, b);
		}
		// test_print_stack(*a, *b);
		crit_a = chk_crit_a(*a);
		crit_b = chk_crit_b(*b);
	}

	crit_a = chk_sort_a(*a);
	crit_b = chk_sort_b(*b);

	// printf("[ROTATING]\n");
	while (!crit_a || !crit_b)
	{
		if (!crit_a && crit_b)
			ra(a);
		else if (crit_a && !crit_b)
			rb(b);
		else
			rr(a, b);
		// test_print_stack(*a, *b);
		crit_a = chk_sort_a(*a);
		crit_b = chk_sort_b(*b);
	}

	// printf("\n[PUSH ALL]\n");
	while (*b)
		pa(a, b);
}

t_bool	chk_med(t_stack *a, int med)
{
	while (a)
	{
		if (a->data < med)
			return (FALSE);
		else
			a = a->next;
	}
	return (TRUE);
}

t_bool	chk_crit_a(t_stack *stack)
{
	int	cnt;

	if (!stack)
		return (TRUE);
	cnt = 0;
	if (stack->data < ft_stklast(stack)->data)
		cnt++;
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			cnt++;
		if (cnt > 1)
			return (FALSE);
		else
			stack = stack->next;
	}
	return (TRUE);
}

t_bool	chk_crit_b(t_stack *stack)
{
	int	cnt;

	if (!stack)
		return (TRUE);
	cnt = 0;
	if (stack->data > ft_stklast(stack)->data)
		cnt++;
	while (stack && stack->next)
	{
		if (stack->data < stack->next->data)
			cnt++;
		if (cnt > 1)
			return (FALSE);
		else
			stack = stack->next;
	}
	return (TRUE);
}

t_bool	chk_sort_a(t_stack *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (FALSE);
		else
			a = a->next;
	}
	return (TRUE);
}

t_bool	chk_sort_b(t_stack *b)
{
	while (b && b->next)
	{
		if (b->data < b->next->data)
			return (FALSE);
		else
			b = b->next;
	}
	return (TRUE);
}

static t_bool	push(t_stack **a, t_stack **b, int med)
{
	if ((*a)->data < med)
	{
		pb(a, b);
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	get_highest(t_stack *stack)
{
	int	high;

	high = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (high < stack->data)
			high = stack->data;
		stack = stack->next;
	}
	return (high);
}

static int	get_lowest(t_stack *stack)
{
	int	low;
	
	low = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (low > stack->data)
			low = stack->data;
		stack = stack->next;
	}
	return (low);
}

static t_bool	chk_lohi(t_stack *stack)
{
	int	hi = get_highest(stack);
	int	lo = get_lowest(stack);

	if (stack->data == hi && stack->next->data == lo)
		return (TRUE);
	else if (stack->data == lo && stack->next->data == hi)
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	swap(t_stack **a, t_stack **b, t_bool crit_a, t_bool crit_b)
{
	if ((chk_null(*a) && chk_null(*b))
		&& !chk_lohi(*a) && !chk_lohi(*b)
		&& !crit_a && !crit_b
		&& ((*a)->data) > (*a)->next->data
		&& (*b)->data < (*b)->next->data)
		ss(*a, *b);
	else if (chk_null(*a) && !chk_lohi(*a) && !crit_a && (*a)->data > (*a)->next->data)
		sa(*a);
	else if (chk_null(*b) && !chk_lohi(*b) && !crit_b && (*b)->data < (*b)->next->data)
		sb(*b);
	else
		return (FALSE);
	return (TRUE);
}

t_bool	chk_null(t_stack *stack)
{
	return (stack && stack->next);
}
