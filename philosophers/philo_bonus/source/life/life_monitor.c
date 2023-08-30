/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:53:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 21:26:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

#include "philo.h"

void	check_death(t_list *data, t_msec *last_meal, t_msec die);

void	*monitor(void *arg)
{
	t_list	*data;

	data = arg;
	semaphore(data, TIMER, IN);
	set_time(data, &data->philo->info.time_last_meal);
	semaphore(data, TIMER, OUT);
	check_death(data,
		&data->philo->info.time_last_meal,
		data->share->config.time_die);
	return (NULL);
}

void	check_death(t_list *data, t_msec *last_meal, t_msec die)
{
	t_msec	elaps;

	while (LOOP)
	{
		semaphore(data, TIMER, IN);
		elaps = get_time_elapsed(data, last_meal);
		semaphore(data, TIMER, OUT);
		// if (get_time_elapsed(data, last_meal) > die)
		if (elaps > die)
		{
			print_death(data);
			semaphore(data, DEATH, OUT);
			break ;
		}
		else
			suspend(10);
	}
}
