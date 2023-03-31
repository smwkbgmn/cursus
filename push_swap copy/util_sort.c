/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:46:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/29 16:16:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_bool	push(t_list **a, t_list **b);
// static t_bool	swap(t_list *a, t_list *b);
// static int		ref(t_list *node);
// static t_bool	chk_sorted(t_list *a, t_list *b);

void	sort(t_list **a, t_list **b)
{
	// int		cnt;
	// t_bool	val_push;
	// t_bool	val_swap;

	while (1)
	{
		if (chk_sorted(*a, *b))
			return ;
		else
		{
			if (ref(*a) 
		}
	}

	// cnt = 0;
	// while (!chk_sorted(*a, *b) && cnt++ < 3)
	// while (*a != NULL && cnt++ < 3)
	// {
	// 	test_print_stack(*a, *b);
	// 	val_push = push(a, b);
	// 	val_swap = swap(*a, *b);
	// 	if (!val_push && !val_swap)
	// 		ra(a);
	// }
	// while (*b != NULL)
	// 	pa(a, b);
}

// static t_bool	push(t_list **a, t_list **b)
// {
// 	if (ref(*a) < 99999)
// 	{
// 		pb(a, b);
// 		return (TRUE);
// 	}
// 	else
// 		return (FALSE);
// }

// static t_bool	swap(t_list *a, t_list *b)
// {
// 	if (a && b && (ref(a) > ref(a->next) && ref(b) < ref(b->next)))
// 		ss(a, b);
// 	else if (a && (ref(a) > ref(a->next)))
// 		sa(a);
// 	else if (b && (ref(b) < ref(b->next)))
// 		sb(b);
// 	else
// 		return (FALSE);
// 	return (TRUE);
// }

// static int	ref(t_list *node)
// {
// 	if (node)
// 		return (*(int *)node->content);
// 	else
// 		return (-1);
// }

// static t_bool	chk_sorted(t_list *a, t_list *b)
// {
// 	if (b != NULL)
// 		return (FALSE);
// 	while (a && a->next != NULL)
// 	{
// 		if (ref(a) > ref(a->next))
// 			return (FALSE);
// 		a = a->next;
// 	}
// 	return (TRUE);
// }
