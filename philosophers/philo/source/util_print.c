/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:20:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:05:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	print_status(t_list *data, t_stat stat)
{
	mtx_lock(&data->program->key_print);
	if (!ref_death(data->program))
	{
		if (stat == THINK)
			printf("%lld %d is thinking\n",
				get_time_elapsed(&data->program->time_sys, NULL),
				data->thread->philo.name);
		else if (stat == EAT)
			printf("%lld %d is eating\n",
				get_time_elapsed(&data->program->time_sys, NULL),
				data->thread->philo.name);
		else if (stat == SLEEP)
			printf("%lld %d is sleeping\n",
				get_time_elapsed(&data->program->time_sys, NULL),
				data->thread->philo.name);
	}
	mtx_unlock(&data->program->key_print);
}

void	print_taking_fork(t_list *data)
{
	mtx_lock(&data->program->key_print);
	if (!ref_death(data->program))
	{
		printf("%lld %d has taken a fork\n",
			get_time_elapsed(&data->program->time_sys, NULL),
			data->thread->philo.name);
	}
	mtx_unlock(&data->program->key_print);
}

void	print_death(t_list *data)
{
	mtx_lock(&data->program->key_print);
	printf("%lld %d died\n",
		get_time_elapsed(&data->program->time_sys, NULL),
		data->thread->philo.name);
	mtx_unlock(&data->program->key_print);
}
