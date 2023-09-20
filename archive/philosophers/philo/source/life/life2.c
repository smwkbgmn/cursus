/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:24:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/20 19:12:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking(t_list *data)
{
	if (data->thread->philo.name % 2 == 1)
	{
		mutex(data->next, FORK, ON);
		print_taking(data);
		mutex(data, FORK, ON);
		if (ref_status(data->prev) == STARVE
			&& ref_status(data->next) == SLEEP)
		{
			mutex(data, FORK, OFF);
			suspend(data, 10);
			mutex(data, FORK, ON);
		}
		print_taking(data);
	}
	else
	{
		mutex(data, FORK, ON);
		print_taking(data);
		mutex(data->next, FORK, ON);
		print_taking(data);
	}
}

void	putting_down(t_list *data)
{
	if (data->thread->philo.name % 2 == 1)
	{
		mutex(data->next, FORK, OFF);
		mutex(data, FORK, OFF);
	}
	else
	{
		mutex(data, FORK, OFF);
		mutex(data->next, FORK, OFF);
	}
}
