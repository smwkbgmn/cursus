/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:20:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 19:40:10 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	print_info(t_thread *thread);
t_bool	philo_dead_while_mtx_wait(t_thread *thread);

void	print_status(t_thread *thread, t_stat stat)
{
	mtx_lock(&thread->data->key_print);
	if (!philo_dead_while_mtx_wait(thread))
	{
		print_info(thread);
		if (stat == THINK)
			printf("is thinking\n");
		else if (stat == EAT)
		{
			printf("has taken a fork\n");
			print_info(thread);
			printf("is eating\n");
		}
		else if (stat == SLEEP)
			printf("is sleeping\n");
		else
			printf("died\n");
	}
	mtx_unlock(&thread->data->key_print);
}

void	print_info(t_thread *thread)
{
	printf("%lld", get_time_elapsed(&thread->data->time_sys));
	printf(" %d ", thread->philo.name);
}

t_bool	philo_dead_while_mtx_wait(t_thread *thread)
{
	return (ref_status(thread) == DEAD);
}
