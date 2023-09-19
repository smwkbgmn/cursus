/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:31:24 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 23:16:02 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	spend_time(unsigned long long time, t_arg *arg)
{
	unsigned long long	start;
	unsigned long long	now;

	start = current_time();
	while (1)
	{
		pthread_mutex_lock(&(arg->end_mutex));
        if((arg->end_flag))
		{
			pthread_mutex_unlock(&(arg->end_mutex));
            break;
		}
		pthread_mutex_unlock(&(arg->end_mutex));
		now = current_time();
		if ((now - start) >= time)
			break ;
		usleep(1000);
	}
}

unsigned long long  current_time(void)
{
	struct timeval	time;
    unsigned long long realtime;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
    realtime = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (realtime);
}

void	sleep_even(t_arg *arg)
{
	struct timeval	get_time;
	struct timeval	timestamp;
	int				time_taken;

	gettimeofday(&get_time, NULL);
	while (1)
	{
		gettimeofday(&timestamp, NULL);
		time_taken = (timestamp.tv_usec - get_time.tv_usec) / 1000 + (timestamp.tv_sec - get_time.tv_sec) * 1000;
		if (time_taken > arg->time_to_eat)
			break ;
		usleep(1000);
	}
}