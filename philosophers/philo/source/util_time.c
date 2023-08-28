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

	set_time(&start, NULL);
	curnt = start;
	while (curnt - start < ms)
	{
		usleep(256);
		set_time(&curnt, NULL);
	}
}

void	set_time(t_msec *time_ms, t_mutex *key)
{
	t_timeval	curnt;

	gettimeofday(&curnt, NULL);
	if (key)
	{
		mtx_lock(key);
		*time_ms = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
		mtx_unlock(key);
	}
	else
		*time_ms = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
}

t_msec	get_time_elapsed(t_time *time, t_mutex *key)
{
	t_msec	result;

	set_time(&time->curnt, NULL);
	if (key)
	{
		mtx_lock(key);
		result = time->curnt - time->start;
		mtx_unlock(key);
		return (result);
	}
	else
		return (time->curnt - time->start);
}
