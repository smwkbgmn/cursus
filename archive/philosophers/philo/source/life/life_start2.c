/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_start2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:54:27 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/20 19:12:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	wakeup_philo(t_list *data);

void	init_philos_odd(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 1;
	while (idx < cnt && !ref_death(data) && wakeup_philo(data))
	{
		data = data->next->next;
		idx += 2;
	}
}

void	init_philos_even(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 2;
	while (idx <= cnt && !ref_death(data) && wakeup_philo(data))
	{
		data = data->next->next;
		idx += 2;
	}
	if (idx - cnt == 1 && !ref_death(data))
	{
		data = data->prev;
		suspend(data, data->program->config.delay_eat);
		wakeup_philo(data);
	}
}

void	join_philos(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 1;
	while (idx <= cnt)
	{
		if (data->thread->id)
			pthread_join(data->thread->id, NULL);
		data = data->next;
		idx++;
	}
	set_death(data);
}

void	join_monitors(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 1;
	while (idx <= cnt)
	{
		if (data->thread->id_monitor)
			pthread_join(data->thread->id_monitor, NULL);
		data = data->next;
		idx++;
	}
}

static t_bool	wakeup_philo(t_list *data)
{
	if (pthread_create(&data->thread->id, NULL, &life, data)
		== SUCCESS)
	{
		if (pthread_create(&data->thread->id_monitor, NULL, &monitor, data)
			== SUCCESS)
			return (TRUE);
	}
	set_death(data);
	return (FALSE);
}
