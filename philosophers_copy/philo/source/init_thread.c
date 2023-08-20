/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:04:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 16:08:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "philo.h"

void	init_threads(t_list *list, t_uint cnt);
void	join_threads(t_list *list, t_uint cnt);
void	*philosopher(void *arg);

void	start_life(t_list *list, t_data *data)
{
	init_threads(list, data->config.cnt_philo);
	join_threads(list, data->config.cnt_philo);
}

void	init_threads(t_list *list, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx < cnt)
	{
		set_time(&list->thread->philo.timer_death.start);
		pthread_create(&list->thread->id, NULL, &thread, list);
		pthread_create(&list->thread->id_monitor, NULL, &monitor, list);
		list = list->next;
		idx++;
	}
}

void	join_threads(t_list *list, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx < cnt)
	{
		pthread_join(list->thread->id_monitor, NULL);
		list = list->next;
		idx++;
	}
}
