/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/01 02:17:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "push_swap.h"

t_bool			check_valid(int ac, char **av);
t_bool			check_duplication(t_stack *a);
t_bool			init_stack(t_stack **a, int ac, char **av);
static t_sort	select_algorithm(t_stack *a);
static t_uint	get_cnt_disorder(t_stack *a);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_sort	sort;

	// test_print_input(av);

	av++;
	a = NULL;
	if (ac > 1 && check_valid(ac, av) && init_stack(&a, ac, av))
	{
		if (check_duplication(a))
		{
			sort = select_algorithm(a);
			sort(a, NULL);
		}
		ft_stkclear(a);
	}
	return (0);
}

static t_sort	select_algorithm(t_stack *a)
{
	t_uint	cnt;

	cnt = get_cnt_disorder;
	if (cnt < 3)
		return (&sort_swap);
	else if (cnt < 5)
		return (&sort_insertion);
	else
		return (&sort_hourglass);
}

static t_uint	get_cnt_disorder(t_stack *a)
{
	t_uint	cnt;

	cnt = 0;
	while (a->next != a)
	{
		if (ref(a) > ref(a->next))
			cnt++;
		a = a->next;
	}
	return (cnt);
}

void	write_error(void)
{
	write(2, "Error\n", 6);
}
