/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:20:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/21 19:13:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	print_status(t_thread *thread, t_stat stat)
{
	mtx_lock(&thread->data->key_print);
	if (!is_dead(thread))
	{
		if (stat == THINK)
			printf("%lld %d is thinking\n",
				get_time_elapsed(&thread->data->time_sys), thread->philo.name);
		else if (stat == EAT)
			printf("%lld %d is eating\n",
				get_time_elapsed(&thread->data->time_sys), thread->philo.name);
		else if (stat == SLEEP)
			printf("%lld %d is sleeping\n",
				get_time_elapsed(&thread->data->time_sys), thread->philo.name);
	}
	mtx_unlock(&thread->data->key_print);
}

void	print_taking_fork(t_thread *thread)
{
	mtx_lock(&thread->data->key_print);
	if (!is_dead(thread))
	{
		printf("%lld %d has taken a fork\n",
			get_time_elapsed(&thread->data->time_sys), thread->philo.name);
	}
	mtx_unlock(&thread->data->key_print);
}

void	print_death(t_thread *thread)
{
	mtx_lock(&thread->data->key_print);
	printf("%lld %d died\n",
		get_time_elapsed(&thread->data->time_sys), thread->philo.name);
	mtx_unlock(&thread->data->key_print);
}
