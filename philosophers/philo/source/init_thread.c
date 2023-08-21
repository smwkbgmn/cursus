/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:04:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/21 22:05:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "philo.h"

t_bool	config_can_not_continue(t_config *config);
void	init_threads(t_list *list, t_uint cnt);
void	detach_threads(t_list *list, t_uint cnt);
void	join_threads(t_list *list, t_uint cnt);

void	start_life(t_list *list, t_data *data)
{
	if (!config_can_not_continue(&data->config))
	{
		init_threads(list, data->config.cnt_philo);
		detach_threads(list, data->config.cnt_philo);
		join_threads(list, data->config.cnt_philo);
	}
}

void	init_threads(t_list *list, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx < cnt && !list->thread->data->philo_death)
	{
		set_time(&list->thread->philo.timer_die.start);
		pthread_create(&list->thread->id_monitor, NULL, &monitor, list);
		pthread_create(&list->thread->id, NULL, &life, list);
		list = list->next;
		idx++;
	}
}

void	detach_threads(t_list *list, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx < cnt)
	{
		pthread_detach(list->thread->id_monitor);
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
		pthread_join(list->thread->id, NULL);
		list = list->next;
		idx++;
	}
}

t_bool	config_can_not_continue(t_config *config)
{
	return (config->cnt_philo == 1
		|| config->delay_die == 0
		|| config->cnt_eat == 0);
}
