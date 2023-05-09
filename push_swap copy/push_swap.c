/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/04 22:10:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "push_swap.h"

t_bool	check_valid(int ac, char **av);
t_bool	check_duplication(t_stack *a);
t_bool	init_stack(t_stack **a, int ac, char **av);
t_sort	select_algorithm(t_stack *a);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_sort	sort;

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

void	write_error(void)
{
	write(2, "Error\n", 6);
}
