/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 18:02:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "philo.h"

void	check_stat(t_thread *thread, t_msec death);

void	*monitor(void *arg)
{
	t_list		*list;

	list = arg;
	check_stat(list->thread, list->thread->data->config.delay_die);
	return (NULL);
}

void	check_stat(t_thread *thread, t_msec death)
{
	if (get_time_elapsed(&thread->philo.timer_death) > death)
	{
		set_status(thread, DEAD);
		print_status(thread, DEAD);
		// pthread_detach(thread->id);
	}
	else
	{
		suspend(5);
		check_stat(thread, death);
	}
}
