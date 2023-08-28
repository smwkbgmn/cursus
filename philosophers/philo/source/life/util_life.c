/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:54:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 03:21:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status(t_list *data, t_stat stat_to_change)
{
	mtx_lock(&data->thread->philo.key_stat);
	data->thread->philo.stat = stat_to_change;
	mtx_unlock(&data->thread->philo.key_stat);
}

t_stat	ref_status(t_list *data)
{
	t_stat	result;

	mtx_lock(&data->thread->philo.key_stat);
	result = data->thread->philo.stat;
	mtx_unlock(&data->thread->philo.key_stat);
	return (result);
}
