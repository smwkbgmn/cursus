/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:20:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/31 01:01:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	print_status(t_list *data, t_stat stat)
{
	mutex(data, PRINT, ON);
	if (!ref_death(data))
	{
		if (stat == THINK)
			printf("%lld %d is thinking\n",
				get_time_elapsed(NULL, &data->program->time_sys),
				data->thread->philo.name);
		else if (stat == EAT)
			printf("%lld %d is eating\n",
				get_time_elapsed(NULL, &data->program->time_sys),
				data->thread->philo.name);
		else if (stat == SLEEP)
			printf("%lld %d is sleeping\n",
				get_time_elapsed(NULL, &data->program->time_sys),
				data->thread->philo.name);
	}
	mutex(data, PRINT, OFF);
}

void	print_taking(t_list *data)
{
	mutex(data, PRINT, ON);
	if (!ref_death(data))
	{
		printf("%lld %d has taken a fork\n",
			get_time_elapsed(NULL, &data->program->time_sys),
			data->thread->philo.name);
	}
	mutex(data, PRINT, OFF);
}

void	print_death(t_list *data)
{
	mutex(data, PRINT, ON);
	if (!ref_death(data))
	{
		set_death(data);
		printf("%lld %d died\n",
			get_time_elapsed(NULL, &data->program->time_sys),
			data->thread->philo.name);
	}
	mutex(data, PRINT, OFF);
}
