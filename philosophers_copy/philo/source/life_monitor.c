/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 19:17:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "philo.h"

void	*thread_monitor(void *arg)
{
	t_thread	*thread;
	t_msec		death;

	thread = ((t_list *)arg)->thread;
	death = thread->data->config.delay_die;
	while (LOOP)
	{
		if (get_time_elapsed(&thread->philo.timer_death) > death)
		{
			print_status(thread, DEAD);
			set_status(thread, DEAD);
			pthread_detach(thread->id);
			break ;
		}
		else
			suspend(5);
	}
	return (NULL);
}
