/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:08:10 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 03:06:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philos_eating(t_list *data)
{
	mutex(data, EATING, ON);
	data->program->philo_meet_eating++;
	mutex(data, EATING, OFF);
}

t_uint	ref_philos_eating(t_list *data)
{
	t_uint	result;

	mutex(data, EATING, ON);
	result = data->program->philo_meet_eating;
	mutex(data, EATING, OFF);
	return (result);
}

t_bool	meet_philos_eating(t_list *data)
{
	if (ref_philos_eating(data) == data->program->config.cnt_philo)
	{
		set_death(data);
		return (TRUE);
	}
	else
		return (FALSE);
}
