/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:48:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 13:02:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_death(t_list *data)
{
	semaphore(data, DEATH, IN);
	data->share->death = TRUE;
	semaphore(data, DEATH, OUT);
}

t_bool	ref_death(t_list *data)
{
	t_bool	result;

	semaphore(data, DEATH, IN);
	result = data->share->death;
	semaphore(data, DEATH, OUT);
	return (result);
}

void	set_philos_eating(t_list *data)
{
	printf("\t\t\tJust increase the cnt of eaten\n");
	semaphore(data, EATING, IN);
	(data->share->cnt_done_eat)++;
	semaphore(data, EATING, OUT);
	printf("\t\t\tNow the cnt of eaten : %d\n",
		data->share->cnt_done_eat);
}

t_bool	all_philos_eaten(t_list *data)
{
	t_bool	result;

	printf("\t\t\tPhilo %d ref the cnt of eaten : %d\n",
		data->philo->info.name, data->share->cnt_done_eat);
	semaphore(data, EATING, IN);
	result = (data->share->cnt_done_eat == data->share->config.cnt_philo);
	if (result)
		set_death(data);
	semaphore(data, EATING, OUT);
	return (result);
}

void	set_status(t_list *data, t_stat stat_to_change)
{
	data->philo->info.stat = stat_to_change;
}

t_stat	ref_status(t_list *data)
{
	return (data->philo->info.stat);
}
