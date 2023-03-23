/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:53:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/23 18:27:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print_input(char **av)
{
	printf("[[input]]\n");
	while (*av)
		printf("[%s]", *(av++));
}

void	test_print_stack(t_list *a, t_list *b)
{
	printf("a            b\n");
	printf("-            -\n");
	while (a || b)
	{
		if (a)
		{
			printf("%-13d", *(int *)a->content);
			a = a->next;
		}
		else
			printf("             ");
		if (b)
		{
			printf("%-13d", *(int *)b->content);
			b = b->next;
		}
		printf("\n");
	}
}

void	test_sample_implement(t_list **a, t_list **b)
{
	sa(*a);
	test_print_stack(*a, *b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	test_print_stack(*a, *b);
	ra(a);
	rb(b);
	test_print_stack(*a, *b);
	rra(a);
	rrb(b);
	test_print_stack(*a, *b);
	sa(*a);
	test_print_stack(*a, *b);
	pa(a, b);
	pa(a, b);
	pa(a, b);
	test_print_stack(*a, *b);
}
