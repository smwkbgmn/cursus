/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/15 23:25:49 by donghyu2         ###   ########.fr       */
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
	t_list	*head_a;
	t_list	*head_b;

	av++;
	// test_print_input(av);
	head_a = NULL;
	head_b = NULL;
	init_stack(&head_a, ac, av);
	// test_print_stack(head);
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
