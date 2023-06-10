/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/06/11 02:42:51 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char			**input;
	t_sort			sort;
	static t_stack	*a;
	static t_stack	*b;

	if (ac > 1)
	{
		input = av + 1;
		if (check_valid(ac, input) && init_stack(&a, ac, input)
			&& check_duplication(a) && ft_stksize(a) > 1)
		{
			sort = select_algorithm(a);
			if (sort)
				sort(&a, &b);
		}
		ft_stkclear(a);
	}
	return (0);
}
