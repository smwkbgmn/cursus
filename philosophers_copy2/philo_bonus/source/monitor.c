/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:08:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 00:05:22 by donghyu2         ###   ########.fr       */
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
		create_thread(data, &data->share->id_mntr_eaten, &monitor_eaten);
	create_thread(data, &data->share->id_mntr_death, &monitor_death);
}

void	join_monitor(t_list *data)
{
	if (data->share->config.cnt_eat != -1)
		detach_thread(data, &data->share->id_mntr_eaten);
	join_thread(data, &data->share->id_mntr_death);
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
		// if (kill(data->philo->id, SIGTERM) == ERROR)
		if (kill(data->philo->id, SIGKILL) == ERROR)
			exit_with_error(data, "kill");
		data = data->next;
	}
	semaphore(data, PRINT, OUT);
}
