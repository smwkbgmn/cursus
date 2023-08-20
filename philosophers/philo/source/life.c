/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:56:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 21:33:48 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *arg)
{
	t_thread	*thread;

	thread = ((t_list *)arg)->thread;
	if (!config_can_not_continue(thread))
	{
		while (ref_status(thread) != DEAD)
			thread->data->routine[thread->philo.stat](arg);
	}
	return (NULL);
}

void	philo_think(t_list *list)
{
	philo_do(list->thread, THINK);
}

void	philo_eat(t_list *list)
{
	// if (ref_fork(list->prev->thread))
	mtx_lock(&list->thread->philo.key_fork_set);
	if (list->prev->thread->philo.fork)
	{
		mtx_unlock(&list->thread->philo.key_fork_set);
		suspend(5);
	}
	else
	{
		list->thread->philo.fork = TRUE;
		mtx_lock(&list->next->thread->philo.key_fork_set);
		if (!philos_dead_while_mtx_wait(list))
		{
			set_time(&list->thread->philo.timer_death.start);
			philo_do(list->thread, EAT);
		}
		list->thread->philo.fork = FALSE;
		mtx_unlock(&list->thread->philo.key_fork_set);
		mtx_unlock(&list->next->thread->philo.key_fork_set);
	}
}

void	philo_sleep(t_list *list)
{
	philo_do(list->thread, SLEEP);
}

void	philo_do(t_thread *thread, t_stat status)
{
	print_status(thread, status);
	if (status == EAT)
		suspend(thread->data->config.delay_eat);
	else if (status == SLEEP)
		suspend(thread->data->config.delay_sleep);
	set_status(thread, (status + 1) % 3);
}
