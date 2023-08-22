/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:56:16 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/22 18:52:58 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life(void *arg)
{
	t_thread	*thread;
	int			cnt_eat;

	thread = ((t_list *)arg)->thread;
	cnt_eat = thread->data->config.cnt_eat;
	if (cnt_eat > 0)
		while (!is_dead(thread) && !meet_cnt_eating(thread, cnt_eat))
			thread->data->routine[thread->philo.stat](arg);
	else
		while (!is_dead(thread))
			thread->data->routine[thread->philo.stat](arg);
	return (NULL);
}

void	philo_think(t_list *list)
{
	philo_do(list->thread, THINK);
}

void	philo_eat(t_list *list)
{
	taking(list->thread, list->next->thread);
	if (!is_dead(list->thread))
	{
		set_time(&list->thread->philo.timer_die.start);
		philo_do(list->thread, EAT);
		list->thread->philo.eating++;
	}
	putting_down(list->thread, list->next->thread);
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
