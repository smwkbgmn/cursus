/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:01:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/21 12:38:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

t_thread	*new_philo(t_uint idx, t_data *data);

void	init_data(int ac, char **av, t_data *data)
{
	data->config.cnt_philo = ft_atoi(*(av + 1));
	data->config.delay_die = ft_atoi(*(av + 2));
	data->config.delay_eat = ft_atoi(*(av + 3));
	data->config.delay_sleep = ft_atoi(*(av + 4));
	if (ac == 6)
		data->config.cnt_eat = ft_atoi(*(av + 5));
	else
		data->config.cnt_eat = -1;
	set_time(&data->time_sys.start);
	mtx_init(&data->key_print);
	mtx_init(&data->key_death);
	data->routine[0] = &philo_think;
	data->routine[1] = &philo_eat;
	data->routine[2] = &philo_sleep;
	data->philo_death = FALSE;
}

void	init_philosophers(t_list **list, t_data *data)
{
	t_uint		idx;
	t_list		*list_new;
	t_thread	*thread;

	idx = 0;
	while (idx < data->config.cnt_philo)
	{
		thread = new_philo(idx, data);
		list_new = ft_lstnew(thread);
		ft_lstadd(list, list_new);
		idx++;
	}
}

t_thread	*new_philo(t_uint idx, t_data *data)
{
	t_thread	*thread;

	thread = malloc(sizeof(t_thread));
	thread->philo.name = idx + 1;
	thread->philo.stat = EAT;
	if (idx % 2 == 0 && idx != data->config.cnt_philo - 1)
		thread->philo.fork = TRUE;
	else
		thread->philo.fork = FALSE;
	thread->philo.eating = 0;
	pthread_mutex_init(&thread->philo.key_fork_set, NULL);
	pthread_mutex_init(&thread->philo.key_fork_ref, NULL);
	pthread_mutex_init(&thread->philo.key_eating, NULL);
	thread->data = data;
	return (thread);
}
