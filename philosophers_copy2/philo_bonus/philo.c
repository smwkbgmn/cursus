/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:00:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 00:43:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

int	main(int ac, char **av)
{
	static t_list	*data;
	static t_vars	share;

	if (validate_input(ac, av))
	{
		init_share(ac, av, &share);
		init_philosophers(&data, &share);
		if (!config_can_not_continue(data))
		{
			set_time(NULL, &share.time_life_begin);
			start_life(data);
		}
		free_data(data, &share);
	}
	return (0);
}
