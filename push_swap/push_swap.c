/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/08 22:03:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*a;
	int *b;
	int	ptr;

	a = init_stack_a(ac, av);
	return (0);
}

char	*init_stack_a(int ac, char **av)
{
	int	*a;
	int	count;

	if (is_there_space(*av))
	{
		
	}
	else
	{
	}
	return (a);
}

t_bool	 is_there_space(char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (*str == ' ');
}
