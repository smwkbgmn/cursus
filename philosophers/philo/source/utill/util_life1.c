/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:54:18 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 02:01:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status(t_list *data, t_stat stat_to_change)
{
	mutex(data, STAT, ON);
	data->thread->philo.stat = stat_to_change;
	mutex(data, STAT, OFF);
}

t_stat	ref_status(t_list *data)
{
	t_stat	result;

	mutex(data, STAT, ON);
	result = data->thread->philo.stat;
	mutex(data, STAT, OFF);
	return (result);
}

void	set_death(t_list *data)
{
	mutex(data, DEATH, ON);
	data->program->philo_death = TRUE;
	mutex(data, DEATH, OFF);
}

t_bool	ref_death(t_list *data)
{
	t_bool	result;

	mutex(data, DEATH, ON);
	result = data->program->philo_death;
	mutex(data, DEATH, OFF);
	return (result);
}
