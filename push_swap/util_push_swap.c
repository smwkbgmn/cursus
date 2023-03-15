/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/16 00:07:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. check input char* valid
// 2. init the stack a
// 3. check existence of duplication with stack a

#include <stdlib.h>

#include "push_swap.h"

void	init_stack(t_list **head, int ac, char **av);

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	av++;
	printf("[[input]]\n");
	test_print_input(av);
	a = NULL;
	b = NULL;
	init_stack(&a, ac, av);
	sa(a);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	// sb(b);
	printf("[[stack_a]]\n");
	test_print_stack(a);
	printf("[[stack_b]]\n");
	test_print_stack(b);
	ss(a, b);
	printf("[[stack_a]]\n");
	test_print_stack(a);
	printf("[[stack_b]]\n");
	test_print_stack(b);
}

void	init_stack(t_list **head, int ac, char **av)
{
	int	*data;

	ac++;
	while (*av)
	{
		data = malloc(sizeof(int));
		*data = ft_atoi(*(av++));
		ft_lstadd_back(head, ft_lstnew(data));
	}
}
