/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:08:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/31 00:20:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "philo.h"

static void	*monitor_death(void *arg);
static void	*monitor_eaten(void *arg);
static void	quit_life(t_list *data);

void	start_monitor(t_list *data)
{
	if (data->share->config.cnt_eat != -1)
		pthread_create(&data->share->id_mntr_eaten, NULL,
			&monitor_eaten, data);
	pthread_create(&data->share->id_mntr_death, NULL,
		&monitor_death, data);
}

void	join_monitor(t_list *data)
{
	if (data->share->config.cnt_eat != -1)
		pthread_detach(data->share->id_mntr_eaten);
	pthread_join(data->share->id_mntr_death, NULL);
}

static void	*monitor_death(void *arg)
{
	semaphore(arg, DEATH, IN);
	quit_life(arg);
	return (NULL);
}

static void	*monitor_eaten(void *arg)
{
	static t_uint	cnt;

	semaphore(arg, EATING, IN);
	if (++cnt != ((t_list *)arg)->share->config.cnt_philo)
		monitor_eaten(arg);
	else
		semaphore(arg, DEATH, OUT);
	return (NULL);
}

static void	quit_life(t_list *data)
{
	t_uint	idx;

	idx = 0;
	while (idx++ < data->share->config.cnt_philo)
	{
		if (kill(data->philo->id, SIGTERM) == ERROR)
			exit_with_error("kill");
		data = data->next;
	}
	semaphore(data, PRINT, OUT);
}
