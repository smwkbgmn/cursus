/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:54:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 21:35:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	config_can_not_continue(t_thread *thread)
{
	t_config	*config;

	config = &thread->data->config;
	if (config->delay_die == 0)
		return (TRUE);
	else if (config->cnt_philo == 1
		|| config->cnt_eat == 0)
	{
		philo_do(thread, THINK);
		return (TRUE);
	}
	else
		return (FALSE);
}

t_bool	philos_dead_while_mtx_wait(t_list *list)
{
	return (ref_status(list->thread) == DEAD
		|| ref_status(list->next->thread) == DEAD);
}

void	set_status(t_thread *thread, t_stat stat_to_change)
{
	mtx_lock(&thread->philo.key_stat);
	if (thread->philo.stat != DEAD)
		thread->philo.stat = stat_to_change;
	mtx_unlock(&thread->philo.key_stat);
}

t_stat	ref_status(t_thread *thread)
{
	t_stat	result;

	mtx_lock(&thread->philo.key_stat);
	result = thread->philo.stat;
	mtx_unlock(&thread->philo.key_stat);
	return (result);
}

t_bool	ref_fork(t_thread *thread)
{
	t_bool	result;

	mtx_lock(&thread->philo.key_fork_ref);
	result = thread->philo.fork;
	mtx_unlock(&thread->philo.key_fork_ref);
	return (result);
}
