/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/22 18:00:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_thread *thread, t_time *timer_die, t_msec delay_die);

void	*monitor(void *arg)
{
	t_thread	*thread;

	thread = ((t_list *)arg)->thread;
	check_death(thread,
		&thread->philo.timer_die, thread->data->config.delay_die);
	return (NULL);
}

void	check_death(t_thread *thread, t_time *timer_die, t_msec delay_die)
{
	while (!is_dead(thread))
	{
		if (get_time_elapsed(timer_die) > delay_die)
		{
			if (!meet_cnt_eating(thread, thread->data->config.cnt_eat))
			{
				set_death(thread);
				print_death(thread);
			}
			break ;
		}
		else
			suspend(10);
	}
}
