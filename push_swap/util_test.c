/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:53:22 by donghyu2          #+#    #+#             */
/*   Updated: 2023/03/14 19:53:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_print_input(char **av)
{
	printf("[[input]]\n");
	while (*av)
		printf("%s\n", *(av++));
}

void	test_print_stack(t_list *head)
{
	while (head)
	{
		printf("%d\n", *(int *)head->content);
		head = head->next;
	}
}
