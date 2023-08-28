/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:24:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:43:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking(t_list *data)
{
	if (data->thread->philo.name % 2 == 1)
	{
		lock_fork(data->next);
		print_taking_fork(data);
		lock_fork(data);
		if (ref_status(data->prev) == STARVE
			&& ref_status(data->next) == SLEEP)
		{
			unlock_fork(data);
			suspend(10);
			lock_fork(data);
		}
		print_taking_fork(data);
	}
	else
	{
		lock_fork(data);
		print_taking_fork(data);
		lock_fork(data->next);
		print_taking_fork(data);
	}
}

void	putting_down(t_list *data)
{
	if (data->thread->philo.name % 2 == 1)
	{
		unlock_fork(data->next);
		unlock_fork(data);
	}
	else
	{
		unlock_fork(data);
		unlock_fork(data->next);
	}
}
