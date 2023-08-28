/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:08:10 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 03:21:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_list *data)
{
	mtx_lock(&data->thread->philo.key_fork);
}

void	unlock_fork(t_list *data)
{
	mtx_unlock(&data->thread->philo.key_fork);
}

void	set_philos_eating(t_vars *prgm)
{
	mtx_lock(&prgm->key_eating);
	prgm->philo_meet_eating++;
	mtx_unlock(&prgm->key_eating);
}

t_uint	ref_philos_eating(t_vars *prgm)
{
	t_uint	result;

	mtx_lock(&prgm->key_eating);
	result = prgm->philo_meet_eating;
	mtx_unlock(&prgm->key_eating);
	return (result);
}

t_bool	meet_philos_eating(t_vars *prgm)
{
	return (ref_philos_eating(prgm) == prgm->config.cnt_philo);
}
