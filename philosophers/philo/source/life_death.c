/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:39:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_list *data, t_time *timer, t_mutex *key, t_msec ms_die);

void	*monitor(void *arg)
{
	t_list	*data;

	data = arg;
	set_time(&data->thread->philo.timer_die.start,
		&data->thread->philo.key_timer);
	check_death(data,
		&data->thread->philo.timer_die,
		&data->thread->philo.key_timer,
		data->program->config.delay_die);
	return (NULL);
}

void	check_death(t_list *data, t_time *timer, t_mutex *key, t_msec ms_die)
{
	while (!ref_death(data->program))
	{
		if (get_time_elapsed(timer, key) > ms_die)
		{
			set_death(data->program);
			print_death(data);
		}
		else
			suspend(10);
	}
}
