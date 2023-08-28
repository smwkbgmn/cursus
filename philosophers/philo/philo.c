/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:12:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 04:17:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_list	*data;
	static t_vars	program;

	if (validate_input(ac, av))
	{
		if (init_program(ac, av, &program)
			&& init_philosophers(&data, &program))
			start_life(data);
		free_data(data, &program);
	}
	return (0);
}
