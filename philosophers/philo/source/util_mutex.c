/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:01:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/21 12:09:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mtx_lock(t_mutex *key)
{
	pthread_mutex_lock(key);
}

void	mtx_unlock(t_mutex *key)
{
	pthread_mutex_unlock(key);
}

void	mtx_init(t_mutex *key)
{
	pthread_mutex_init(key, NULL);
}

void	mtx_free(t_mutex *key)
{
	pthread_mutex_destroy(key);
}
