/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/23 18:53:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	push(t_list **a, t_list **b);
static t_bool	swap(t_list *a, t_list *b);
static int		ref(t_list *node);
static t_bool	chk_disorder(t_list *a, t_list *b);

void	sort(t_list **a, t_list **b)
{
	int		cnt;
	t_bool	val_push;
	t_bool	val_swap;

	cnt = 0;
	while (!chk_disorder(*a, *b) && cnt++ < 30)
	{
		val_push = push(a, b);
		val_swap = swap(*a, *b);
		if (!val_push && !val_swap)
		{
			test_print_stack(*a, *b);
			ra(a);
		}
	}
}

static t_bool	push(t_list **a, t_list **b)
{
	if (ref(*a) < 9)
	{
		pb(a, b);
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_bool	swap(t_list *a, t_list *b)
{
	if (ref(a) < ref(a->next) && ref(b) > ref(b->next))
		return (FALSE);
	else
	{
		if (ref(a) > ref(a->next))
		{
			if (ref(b) > ref(b->next))
				sa(a);
			else
				ss(a, b);
		}
		else
			sb(b);
		return (TRUE);
	}
}

static int	ref(t_list *node)
{
	if (node)
		return (*(int *)node->content);
	else
		return (-1);
}

static t_bool	chk_disorder(t_list *a, t_list *b)
{
	if (b != NULL)
		return (FALSE);
	while (a && a->next != NULL)
	{
		if (ref(a) > ref(a->next))
			return (FALSE);
		a = a->next;
	}
	return (TRUE);
}
