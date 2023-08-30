/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:00:59 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 21:18:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "philo.h"

int	main(int ac, char **av)
{
	static t_list	*data;
	static t_vars	*share;

	if (validate_input(ac, av))
	{
		del_semaphore();
		init_share(ac, av, &share);
		init_philosophers(&data, share);
		set_time(NULL, &share->time_life_begin);
		// set_time_p(&share->time_life_begin);
		start_life(data);
	}
	free_data(data);
	return (0);
}

void	*monitor_death(void *arg)
{
	semaphore(arg, DEATH, IN);
	// printf("\t\t\tmonitor death\n");
	quit_life(arg);
	return (NULL);
}

void	*monitor_eaten(void *arg)
{
	static t_uint	cnt;

	semaphore(arg, EATING, IN);
	// printf("\t\t\tmonitor eaten\n");
	if (++cnt != ((t_list *)arg)->share->config.cnt_philo)
		monitor_eaten(arg);
	else
		semaphore(arg, DEATH, OUT);
	return (NULL);
}

void	quit_life(t_list *data)
{
	t_uint	idx;

	idx = 0;
	while (idx++ < data->share->config.cnt_philo)
	{
		if (kill(data->philo->id, SIGTERM) == ERROR)
			exit_with_error("kill");
		data = data->next;
	}
}
