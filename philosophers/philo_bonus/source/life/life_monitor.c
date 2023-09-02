/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:08:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/03 01:40:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "philo.h"

static void	quit_life(t_list *data);

void	*monitor_death(void *arg)
{
	semaphore(arg, DEATH, IN);
	quit_life(arg);
	return (NULL);
}

void	*monitor_eaten(void *arg)
{
	static t_uint	cnt;

	semaphore(arg, EATING, IN);
	if (++cnt != ((t_list *)arg)->share->config.cnt_philo)
		monitor_eaten(arg);
	else
	{
		semaphore(arg, PRINT, IN);
		set_meet_eat(arg);
		semaphore(arg, DEATH, OUT);
	}
	return (NULL);
}

static void	quit_life(t_list *data)
{
	t_uint	idx;

	idx = 0;
	while (idx++ < data->share->config.cnt_philo)
	{
		if (kill(data->philo->id, SIGKILL) == ERROR)
			exit_with_error("kill");
		if (!ref_meet_eat(data))
			semaphore(data, EATING, OUT);
		data = data->next;
	}
	semaphore(data, PRINT, OUT);
}
