/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:00:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 13:09:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_list	*data;
	static t_vars	*share;

	if (validate_input(ac, av))
	{
		init_share(ac, av, &share);
		init_philosophers(&data, share);
		set_time(NULL, &share->time_life_begin);
		printf("the configs : %d %lld %lld %lld %d\n",
			share->config.cnt_philo,
			share->config.time_die,
			share->config.time_eat,
			share->config.time_sleep,
			share->config.cnt_eat);
		start_life(data);
		// free_data();
	}
	exit_with_error("here is the main exit");
	return (0);
}
