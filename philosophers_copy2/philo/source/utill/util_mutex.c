/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:01:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 03:58:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mtx_do(t_mutex *key, t_switch lock);
static int	mtx_init(t_mutex *key);

void	mutex(t_list *data, t_keyname name, t_switch lock)
{
	if (name < 3)
	{
		if (mtx_do(&data->program->key[name], lock) != SUCCESS)
			set_death(data);
	}
	else
		if (mtx_do(&data->thread->philo.key[name % 3], lock) != SUCCESS)
			set_death(data);
}

t_bool	init_keys(t_mutex *key)
{
	t_uint	idx;

	idx = 0;
	while (idx < 3 && mtx_init(&key[idx]) == SUCCESS)
		idx++;
	return (idx == 3);
}

void	mtx_free(t_mutex *key)
{
	pthread_mutex_destroy(key);
}

static int	mtx_init(t_mutex *key)
{
	return (pthread_mutex_init(key, NULL));
}

static int	mtx_do(t_mutex *key, t_switch lock)
{
	if (lock)
		return (pthread_mutex_lock(key));
	else
		return (pthread_mutex_unlock(key));
}
