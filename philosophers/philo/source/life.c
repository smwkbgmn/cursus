/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:56:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:43:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *arg)
{
	t_list	*data;

	data = arg;
	while (!ref_death(data->program) && !meet_philos_eating(data->program))
		data->program->routine[data->thread->philo.stat](data);
	return (NULL);
}

void	philo_think(t_list *data)
{
	philo_do(data, THINK);
}

void	philo_eat(t_list *data)
{
	if (++(data->thread->philo.eating)
		== data->program->config.cnt_eat)
		set_philos_eating(data->program);
	taking(data);
	if (!ref_death(data->program))
	{
		set_status(data, EAT);
		set_time(&data->thread->philo.timer_die.start,
			&data->thread->philo.key_timer);
		philo_do(data, EAT);
	}
	putting_down(data);
}

void	philo_sleep(t_list *data)
{
	philo_do(data, SLEEP);
}

void	philo_do(t_list *data, t_stat status)
{
	print_status(data, status);
	if (status == EAT)
		suspend(data->program->config.delay_eat);
	else if (status == SLEEP)
		suspend(data->program->config.delay_sleep);
	set_status(data, (status + 1) % 4);
}
