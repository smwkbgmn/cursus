/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/25 09:14:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

void	init_stack(t_stack **head, int ac, char **av);
void	fill_order(t_stack *a);
t_uint	get_order(t_stack *a, int num);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;

	// test_print_input(av);

	init_stack(&a, ac, ++av);
	fill_order(a);
	sort(&a, &b);

	// printf("\n[FINISH]\n");
	// test_print_stack(a, b);
}

void	init_stack(t_stack **head, int ac, char **av)
{
	if (ac)
	{
		while (*av)
			ft_stkadd_back(head, ft_stknew(ft_atoi(*(av++))));
	}
}

void	fill_order(t_stack *a)
{
	t_stack	*stk;

	stk = a;
	while (stk)
	{
		stk->order = get_order(stk, stk->data);
		stk = stk->next;
		if (stk == a)
			break ;
	}
}

t_uint	get_order(t_stack *a, int num)
{
	t_stack	*stk;
	t_uint	order;

	stk = a;
	order = 0;
	while (stk)
	{
		if (stk->data < num)
			order++;
		stk = stk->next;
		if (stk == a)
			break ;
	}
	return (order);
}

t_uint	ref(t_stack *stk)
{
	if (stk)
		return (stk->order);
	else
		return (0);
}
