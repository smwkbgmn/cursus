/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/23 18:27:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

void	init_stack(t_list **head, int ac, char **av);

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;

	// 1. Check valid
	// - integer
	// - is it sorted
	// 2. Check the count of disordered data &
	// select best algorithm
	// - sorted backward 
	// - small amount
	// - large amount

	init_stack(&a, ac, ++av);
	// test_sample_implement(&a, &b);
	sort(&a, &b);
	test_print_stack(a, b);
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
