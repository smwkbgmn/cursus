/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:56:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 18:50:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_lock(t_list *list);
void	eat_unlock(t_list *list);

void	*thread(void *arg)
{
	t_list	*list;

	list = arg;
	while (ref_status(list->thread) != DEAD)
		philo_do(list, list->thread, ref_status(list->thread));
	return (NULL);
}

void	philo_do(t_list *list, t_thread *thread, t_stat stat)
{
	if (stat == EAT)
		eat_lock(list);
	if (ref_status(thread) != DEAD
		&& (stat != EAT || ref_status(list->next->thread) != DEAD))
	{
		print_status(thread, stat);
		if (stat == EAT)
		{
			set_time(&thread->philo.timer_death.start);
			suspend(thread->data->config.delay_eat);
		}
		else if (stat == SLEEP)
			suspend(thread->data->config.delay_sleep);
		set_status(thread, (stat + 1) % 3);
	}
	if (stat == EAT)
		eat_unlock(list);
}

void	eat_lock(t_list *list)
{
	mtx_lock(&list->thread->philo.key_fork);
	if (list->prev->thread->philo.fork == TRUE)
	{
		mtx_unlock(&list->thread->philo.key_fork);
		suspend(5);
		eat_lock(list);
	}
	else
	{
		list->thread->philo.fork = TRUE;
		mtx_lock(&list->next->thread->philo.key_fork);
	}
}

void	eat_unlock(t_list *list)
{
	list->thread->philo.fork = FALSE;
	mtx_unlock(&list->thread->philo.key_fork);
	mtx_unlock(&list->next->thread->philo.key_fork);
}
