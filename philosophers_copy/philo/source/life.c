/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:56:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 16:52:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life(t_list *list);

void	*thread(void *arg)
{
	life(arg);
	return (NULL);
}

void	life(t_list *list)
{
	while (ref_status(list->thread) != DEAD)
		list->thread->data->routine[list->thread->philo.stat](list);
}

void	philo_think(t_list *list)
{
	philo_do(list->thread, THINK);
}

void	philo_eat(t_list *list)
{
	mtx_lock(&list->thread->philo.key_fork);
	if (list->prev->thread->philo.fork == TRUE)
	{
		mtx_unlock(&list->thread->philo.key_fork);
		suspend(5);
	}
	else
	{
		list->thread->philo.fork = TRUE;
		mtx_lock(&list->next->thread->philo.key_fork);
		if (ref_status(list->thread) != DEAD
			&& ref_status(list->next->thread) != DEAD)
		{
			set_time(&list->thread->philo.timer_death.start);
			philo_do(list->thread, EAT);
		}
		list->thread->philo.fork = FALSE;
		mtx_unlock(&list->thread->philo.key_fork);
		mtx_unlock(&list->next->thread->philo.key_fork);
	}
}

void	philo_sleep(t_list *list)
{
	philo_do(list->thread, SLEEP);
}
