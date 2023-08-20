/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:06 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/20 21:38:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_thread *thread, t_msec death);
void	check_death_with_eating(t_thread *thread, t_msec death, int cnt_eat);
t_bool	meet_cnt_eating(t_thread *thread, int cnt_eat);

void	*monitor(void *arg)
{
	t_thread	*thread;
	t_msec		death;
	int			eat;

	thread = ((t_list *)arg)->thread;
	death = thread->data->config.delay_die;
	eat = thread->data->config.cnt_eat;
	if (eat == -1)
		check_death(thread, death);
	else
		check_death_with_eating(thread, death, eat);
	return (NULL);
}

void	check_death(t_thread *thread, t_msec death)
{
	while (LOOP)
	{
		if (get_time_elapsed(&thread->philo.timer_death) > death)
		{
			print_status(thread, DEAD);
			set_status(thread, DEAD);
			pthread_detach(thread->id);
			break ;
		}
		else
			suspend(10);
	}
}

void	check_death_with_eating(t_thread *thread, t_msec death, int cnt_eat)
{
	while (LOOP)
	{
		if (get_time_elapsed(&thread->philo.timer_death) > death
			|| meet_cnt_eating(thread, cnt_eat))
		{
			print_status(thread, DEAD);
			set_status(thread, DEAD);
			pthread_detach(thread->id);
			break ;
		}
		else
			suspend(10);
	}
}

t_bool	meet_cnt_eating(t_thread *thread, int cnt_eat)
{
	return (thread->philo.eating == cnt_eat);
}
