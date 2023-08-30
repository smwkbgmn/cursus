/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:26:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 19:07:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_monitor(t_list *data)
{
	pthread_create(&data->philo->id_monitor, NULL, &monitor, data);
}

void	join_monitor(t_list *data)
{
	// pthread_join(data->philo->id_monitor, NULL);
	pthread_detach(data->philo->id_monitor);
}
