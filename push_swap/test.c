/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:53:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/06 14:46:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

void	test_print_input(char **av)
{
	printf("\n[[input]]\n");
	while (*av)
	{
		printf("%s", *(av++));
		if (*av)
			printf(" ");
	}
	printf("\n");
}

// void	test_print_stack(t_stack *a, t_stack *b)
// {
// 	t_stack	*head_a;
// 	t_stack	*head_b;

// 	head_a = a;
// 	head_b = b;
// 	printf("\n");
// 	printf("a            b\n");
// 	printf("-            -\n");
// 	while (a || b)
// 	{
// 		if (a)
// 		{
// 			printf("%-13d", a->data);
// 			if (a->next == head_a)
// 				a = NULL;
// 			else
// 				a = a->next;
// 		}
// 		else
// 			printf("             ");
// 		if (b)
// 		{
// 			printf("%-13d", b->data);
// 			if (b->next == head_b)
// 				b = NULL;
// 			else
// 				b = b->next;
// 		}
// 		printf("\n");
// 	}
// 	printf("\n");
// }

void	test_print_stack(t_stack *a, t_stack *b)
{
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = a;
	node_b = b;
	printf("\na\n-\n");
	while (node_a)
	{
		printf("%d\n", node_a->data);
		if (node_a->next == a)
			node_a = NULL;
		else
			node_a = node_a->next;
	}
	printf("-\n");

	printf("\nb\n-\n");
	while (node_b)
	{
		printf("%d\n", node_b->data);
		if (node_b->next == b)
			node_b = NULL;
		else
			node_b = node_b->next;
	}
	printf("-\n\n");
}

void	test_sample_implement(t_stack **a, t_stack **b)
{
	sa(*a);
	test_print_stack(*a, *b);
	pb(a, b);
	pb(a, b);
	// pb(a, b);
	test_print_stack(*a, *b);
	// ra(a);
	// rb(b);
	// test_print_stack(*a, *b);
	// rra(a);
	// rrb(b);
	// test_print_stack(*a, *b);
	// sa(*a);
	// test_print_stack(*a, *b);
	// pa(a, b);
	// pa(a, b);
	// pa(a, b);
	// test_print_stack(*a, *b);
}