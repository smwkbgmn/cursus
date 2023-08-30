/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:34:20 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/31 00:22:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	suspend(t_msec ms)
{
	t_msec	start;
	t_msec	curnt;

	set_time(NULL, &start);
	curnt = start;
	while (curnt - start < ms)
	{
		if (usleep(256) == ERROR)
			exit_with_error("usleep");
		set_time(NULL, &curnt);
	}
}

void	set_time(t_list *data, t_msec *time)
{
	t_timeval	curnt;

	if (gettimeofday(&curnt, NULL) == ERROR)
		exit_with_error("gettimeofday");
	if (data)
	{
		semaphore(data, TIMER, IN);
		*time = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
		semaphore(data, TIMER, OUT);
	}
	else
		*time = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
}

t_msec	get_time_elapsed(t_list *data, t_msec *start)
{
	t_msec	curnt;
	t_msec	result;

	set_time(NULL, &curnt);
	if (data)
	{
		semaphore(data, TIMER, IN);
		result = curnt - *start;
		semaphore(data, TIMER, OUT);
		return (result);
	}
	else
		return (curnt - *start);
}
