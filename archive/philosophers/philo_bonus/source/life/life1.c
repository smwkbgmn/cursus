/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:29:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/03 01:41:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_do(t_list *data, t_stat status);

void	life(t_list *data)
{
	semaphore(data, DEATH, IN);
	semaphore(data, EATING, IN);
	start_timer(data);
	detach_timer(data);
	while (LOOP && data)
		data->share->routine[data->philo->info.stat](data);
}

void	philo_think(t_list *data)
{
	philo_do(data, THINK);
}

void	philo_eat(t_list *data)
{
	taking(data);
	set_status(data, EAT);
	set_time(data, &data->philo->info.time_last_meal);
	philo_do(data, EAT);
	putting_down(data);
}

void	philo_sleep(t_list *data)
{
	philo_do(data, SLEEP);
}

static void	philo_do(t_list *data, t_stat status)
{
	print_status(data, status);
	if (status == EAT)
	{
		if (++(data->philo->info.eating)
			== data->share->config.cnt_eat)
			semaphore(data, EATING, OUT);
		suspend(data->share->config.time_eat);
	}
	else if (status == SLEEP)
		suspend(data->share->config.time_sleep);
	set_status(data, (status + 1) % 4);
}
