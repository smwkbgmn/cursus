/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:31:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:13:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philo.h"

void	suspend(t_msec ms)
{
	t_msec	start;
	t_msec	curnt;

	set_time(NULL, &start);
	curnt = start;
	while (curnt - start < ms)
	{
		usleep(256);
		set_time(NULL, &curnt);
	}
}

void	set_time(t_list *data, t_msec *time_ms)
{
	t_timeval	curnt;

	gettimeofday(&curnt, NULL);
	if (data)
	{
		mutex(data, TIMER, ON);
		*time_ms = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
		mutex(data, TIMER, OFF);
	}
	else
		*time_ms = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
}

t_msec	get_time_elapsed(t_list *data, t_time *time)
{
	t_msec	result;

	set_time(NULL, &time->curnt);
	if (data)
	{
		mutex(data, TIMER, ON);
		result = time->curnt - time->start;
		mutex(data, TIMER, OFF);
		return (result);
	}
	else
		return (time->curnt - time->start);
}
