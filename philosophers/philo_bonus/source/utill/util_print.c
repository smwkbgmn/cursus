/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 01:04:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 18:36:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_list *data, t_stat stat)
{
	semaphore(data, PRINT, IN);
	if (stat == THINK)
		printf("%lld %d is thinking\n",
			get_time_elapsed(NULL, &data->share->time_life_begin),
			data->philo->info.name);
	else if (stat == EAT)
		printf("%lld %d is eating\n",
			get_time_elapsed(NULL, &data->share->time_life_begin),
			data->philo->info.name);
	else if (stat == SLEEP)
		printf("%lld %d is sleeping\n",
			get_time_elapsed(NULL, &data->share->time_life_begin),
			data->philo->info.name);
	semaphore(data, PRINT, OUT);
}

void	print_taking(t_list *data)
{
	semaphore(data, PRINT, IN);
	printf("%lld %d has taken a fork\n",
		get_time_elapsed(NULL, &data->share->time_life_begin),
		data->philo->info.name);
	semaphore(data, PRINT, OUT);
}

void	print_death(t_list *data)
{
	semaphore(data, PRINT, IN);
	printf("%lld %d died\n",
		get_time_elapsed(NULL, &data->share->time_life_begin),
		data->philo->info.name);
	semaphore(data, PRINT, OUT);
}
