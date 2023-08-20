/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:31:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 16:08:30 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philo.h"

void	suspend(t_msec ms)
{
	t_msec	start;
	t_msec	curnt;

	set_time(&start);
	curnt = start;
	while (curnt - start < ms)
	{
		usleep(256);
		set_time(&curnt);
	}
}

void	set_time(t_msec *time_ms)
{
	t_timeval	curnt;

	gettimeofday(&curnt, NULL);
	*time_ms = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
}

t_msec	get_time_elapsed(t_time *time)
{
	set_time(&time->curnt);
	return (time->curnt - time->start);
}
