/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/09 17:05:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1. check input char* valid
// 2. init the stack a
// 3. check existence of duplication with stack a

#include <stdio.h>
#include <stddef.h>

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*a;
	int	*b;
	int	cnt;

	a = init_stack_a(ac, av, *cnt);
	b = ft_calloc(cnt, sizeof(int));
	return (0);
}

int	*init_stack(int ac, char **av, int *cnt)
{
	int	*stack;
	int	idx;

	idx = 0;
	if (ac == 1)
	{
		*cnt = get_cnt(av[1]);
		stackr = ft_calloc(*cnt, sizeof(int));
		while (idx < cnt)
		{
			stack[idx] = 
		}
	}
	else
	{
		*cnt = ac - 1;
		stack = ft_calloc(*cnt, sizeof(int));
		while (idx < cnt)
		{
			stack[idx] = ft_atoi(av[idx + 1]);
			idx++;
		}
	}
}

int	get_cnt(char *input)
{
	int	cnt;

	cnt = 0;
	while (*input)
	{
		if (ft_isdigit(*input))
			cnt++;
		input += move_to_next_num(input);
	}
	return (cnt);
}

int	*move_to_next_num(char *input)
{
	int	idx;

	idx = 0;
	while (ft_isdigit(input[idx]))
		idx++;
	// check if the continuous space is a error or not 
	// if (*input == ' ')
	// 	input++;
	while (input[idx] == ' ')
		idx++;
	return (idx);
}
