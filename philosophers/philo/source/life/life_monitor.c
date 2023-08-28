/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 02:56:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_list *data, t_time *timer, t_msec ms_die);

void	*monitor(void *arg)
{
	t_list	*data;

	data = arg;
	set_time(data, &data->thread->philo.timer_die.start);
	check_death(data,
		&data->thread->philo.timer_die,
		data->program->config.delay_die);
	return (NULL);
}

void	check_death(t_list *data, t_time *timer, t_msec ms_die)
{
	while (!ref_death(data))
	{
		if (get_time_elapsed(data, timer) > ms_die)
		{
			set_death(data);
			print_death(data);
		}
		else
			suspend(10);
	}
}
