/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:20:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 18:50:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "philo.h"

void	print_name(t_thread *thread);
void	print_time(t_time *time);

void	print_status(t_thread *thread, t_stat stat)
{
	mtx_lock(&thread->data->key_print);
	if (ref_status(thread) != DEAD)
	{
		print_time(&thread->data->time_sys);
		print_name(thread);
		if (stat == THINK)
			printf("is thinking\n");
		else if (stat == EAT)
		{
			printf("has taken a fork\n");
			print_time(&thread->data->time_sys);
			print_name(thread);
			printf("is eating\n");
		}
		else if (stat == SLEEP)
			printf("is sleeping\n");
		else
			printf("died\n");
	}
	mtx_unlock(&thread->data->key_print);
}

void	print_name(t_thread *thread)
{
	printf(" %d ", thread->philo.name);
}

void	print_time(t_time *time)
{
	printf("%lld", get_time_elapsed(time));
}
