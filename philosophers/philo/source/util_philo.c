/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:54:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/21 21:40:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status(t_thread *thread, t_stat stat_to_change)
{
	thread->philo.stat = stat_to_change;
}

void	set_fork(t_thread *thread, t_bool bool_to_set)
{
	mtx_lock(&thread->philo.key_fork_ref);
	thread->philo.fork = bool_to_set;
	mtx_unlock(&thread->philo.key_fork_ref);
}

t_bool	ref_fork(t_thread *thread)
{
	t_bool	result;

	mtx_lock(&thread->philo.key_fork_ref);
	result = thread->philo.fork;
	mtx_unlock(&thread->philo.key_fork_ref);
	return (result);
}

void	set_death(t_thread *thread)
{
	mtx_lock(&thread->data->key_death);
	thread->data->philo_death = TRUE;
	mtx_unlock(&thread->data->key_death);
}

t_bool	is_dead(t_thread *thread)
{
	t_bool	result;

	mtx_lock(&thread->data->key_death);
	result = thread->data->philo_death;
	mtx_unlock(&thread->data->key_death);
	return (result);
}

void	set_eating(t_thread *thread)
{
	// mtx_lock(&thread->philo.key_eating);
	thread->philo.eating++;
	// mtx_unlock(&thread->philo.key_eating);
}

int	ref_eating(t_thread *thread)
{
	int	result;

	// mtx_lock(&thread->philo.key_eating);
	result = thread->philo.eating;
	// mtx_unlock(&thread->philo.key_eating);
	return (result);
}
