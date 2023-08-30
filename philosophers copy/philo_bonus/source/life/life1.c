/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:29:41 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 12:52:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_do(t_list *data, t_stat status);

void	life(t_list *data)
{
	start_monitor(data);
	while (!ref_death(data) && !all_philos_eaten(data))
	{
		printf("\t\t\tPhilo %d ref death : %d\n",
			data->philo->info.name, ref_death(data));
		data->share->routine[data->philo->info.stat](data);
	}
	join_monitor(data);
}

void	philo_think(t_list *data)
{
	philo_do(data, THINK);
}

void	philo_eat(t_list *data)
{
	taking(data);
	if (!ref_death(data))
	{
		set_status(data, EAT);
		set_time(data, &data->philo->info.time_last_meal);
		if (++(data->philo->info.eating) == data->share->config.cnt_eat)
		{
			printf("\t\t\tJust passed if\n");
			set_philos_eating(data);
		}
		philo_do(data, EAT);
		printf("\t\t\tPhilo %d eating : %d\n",
			data->philo->info.name, data->philo->info.eating);
	}
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
		suspend(data->share->config.time_eat);
	else if (status == SLEEP)
		suspend(data->share->config.time_sleep);
	set_status(data, (status + 1) % 4);
}
