/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 22:08:34 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 23:41:44 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_meet_eat(t_list *data)
{
	semaphore(data, EATING_CHANGE, IN);
	data->share->meet_all_eat = TRUE;
	semaphore(data, EATING_CHANGE, OUT);
}

t_bool	ref_meet_eat(t_list *data)
{
	t_bool	result;

	semaphore(data, EATING_CHANGE, IN);
	result = data->share->meet_all_eat;
	semaphore(data, EATING_CHANGE, OUT);
	return (result);
}

void	start_monitor(t_list *data)
{
	if (!ref_meet_eat(data))
		create_thread(data, &data->share->id_mntr_eaten, &monitor_eaten);
	create_thread(data, &data->share->id_mntr_death, &monitor_death);
}

void	join_monitor(t_list *data)
{
	if (!ref_meet_eat(data))
		join_thread(&data->share->id_mntr_eaten);
	join_thread(&data->share->id_mntr_death);
}
