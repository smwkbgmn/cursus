/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_start1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:04:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 04:34:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	config_can_not_continue(t_list *data);
static void		init_philo_one(t_list *data);

void	start_life(t_list *data)
{
	t_uint		cnt_philo;

	if (!config_can_not_continue(data))
	{
		cnt_philo = data->program->config.cnt_philo;
		set_time(NULL, &data->program->time_sys.start);
		if (cnt_philo == 1)
			init_philo_one(data);
		else
		{
			init_philos_odd(data, cnt_philo);
			init_philos_even(data->next, cnt_philo);
			join_philos(data, cnt_philo);
			join_monitors(data, cnt_philo);
		}
	}
}

static t_bool	config_can_not_continue(t_list *data)
{
	return (!data
		|| data->program->config.delay_die == 0
		|| data->program->config.cnt_eat == 0);
}

static void	init_philo_one(t_list *data)
{
	pthread_t	id;

	if (pthread_create(&id, NULL, &life_one, data) != SUCCESS)
		set_death(data);
	else
		pthread_join(id, NULL);
}
