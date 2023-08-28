/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:04:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:41:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "philo.h"

void	init_philos_odd(t_list *data, t_uint cnt);
void	init_philos_even(t_list *data, t_uint cnt);
void	join_philos(t_list *data, t_uint cnt);
void	join_monitors(t_list *data, t_uint cnt);

void	start_life(t_list *data)
{
	t_uint	cnt_philo;

	if (!config_can_not_continue(&data->program->config))
	{
		cnt_philo = data->program->config.cnt_philo;
		set_time(&data->program->time_sys.start, NULL);
		init_philos_odd(data, cnt_philo);
		init_philos_even(data->next, cnt_philo);
		join_philos(data, cnt_philo);
		join_monitors(data, cnt_philo);
	}
}

void	init_philos_odd(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 1;
	while (idx < cnt && !ref_death(data->program))
	{
		pthread_create(&data->thread->id, NULL, &life, data);
		pthread_create(&data->thread->id_monitor, NULL, &monitor, data);
		data = data->next->next;
		idx += 2;
	}
}

void	init_philos_even(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 2;
	while (idx <= cnt && !ref_death(data->program))
	{
		pthread_create(&data->thread->id, NULL, &life, data);
		pthread_create(&data->thread->id_monitor, NULL, &monitor, data);
		data = data->next->next;
		idx += 2;
	}
	if (idx - cnt == 1)
	{
		data = data->prev;
		suspend(data->program->config.delay_eat);
		pthread_create(&data->thread->id, NULL, &life, data);
		pthread_create(&data->thread->id_monitor, NULL, &monitor, data);
	}
}

void	join_philos(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 1;
	while (idx <= cnt)
	{
		pthread_join(data->thread->id, NULL);
		data = data->next;
		idx++;
	}
	set_death(data->program);
}

void	join_monitors(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 1;
	while (idx <= cnt)
	{
		pthread_join(data->thread->id_monitor, NULL);
		data = data->next;
		idx++;
	}
}
