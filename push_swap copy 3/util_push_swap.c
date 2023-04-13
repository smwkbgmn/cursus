/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/13 20:08:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. Check valid
	// - integer
	// - is it sorted
	// 2. Check the count of disordered data & select best algorithm
	// - sorted backward 
	// - small amount
	// - large amount

#include <stdlib.h>

#include "push_swap.h"

void	init_stack(t_stack **head, char **av);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av++;
	ac++;
	// test_print_input(av);

	init_stack(&a, av);
	sort(&a, &b);


	// printf("\n[FINISH]\n");
	// test_print_stack(a, b);
}

void	init_stack(t_stack **head, char **av)
{
	while (*av)
		ft_stkadd_back(head, ft_stknew(ft_atoi(*(av++))));
}
