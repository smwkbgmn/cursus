/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/03 01:47:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "push_swap.h"

t_bool			check_valid(int ac, char **av);
t_bool			check_duplication(t_stack *a);
t_bool			init_stack(t_stack **a, int ac, char **av);
static t_sort	select_algorithm(t_stack *a);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_sort	sort;

	// test_print_input(av);

	av++;
	a = NULL;
	b = NULL;
	if (ac > 1 && check_valid(ac, av) && init_stack(&a, ac, av))
	{
		if (check_duplication(a))
		{
			sort = select_algorithm(a);
			if (sort)
				sort(&a, &b);
		}
		ft_stkclear(a);
	}
	return (0);
}

static t_sort	select_algorithm(t_stack *a)
{
	t_uint	size;
	t_uint	cnt;

	size = ft_stksize(a);
	cnt = get_cnt_disorder(a);
	if (cnt == 0)
		return (NULL);
	else if (size <= 3)
		return (&sort_3);
	else if (size <= 5)
		return (&sort_5);
	// else if (size > 5 && cnt <= 32)
	// 	return (&sort_insertion);
	else
		return (&sort_hourglass);
}

t_uint	get_cnt_disorder(t_stack *a)
{
	t_stack	*stk;
	t_uint	cnt;

	stk = a;
	cnt = 0;
	while (stk->next != a)
	{
		if (ref(stk) > ref(stk->next))
			cnt++;
		stk = stk->next;
	}
	return (cnt);
}

void	write_error(void)
{
	write(2, "Error\n", 6);
}
