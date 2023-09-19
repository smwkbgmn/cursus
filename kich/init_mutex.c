/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:04:34 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 22:18:50 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_init(t_arg *arg)
{
	int	i;
	int	num;

	i = 0;
	num = arg->num_philosophers;
	arg->forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!(arg->forks))
    {
        printf("fork memory allocation error!\n");
		return (1);
    }
	while (i < num)
	{
		if (pthread_mutex_init(&(arg->forks[i]), NULL) != 0)
        {
			printf("mutex error!\n");
            return (1);
        }
		i++;
	}
	return (0);
}

int	init_mutex(t_arg *arg)
{
	int	i;

	if (pthread_mutex_init(&(arg->print), NULL) || pthread_mutex_init(&(arg->count_mutex), NULL) \
	|| pthread_mutex_init(&(arg->init_thread), NULL) || pthread_mutex_init(&(arg->end_mutex), NULL) \
	|| pthread_mutex_init(&(arg->time), NULL) || (fork_init(arg)))
	{
		printf("mutex error!\n");
		return (1);
	}
	return (0);
}

void	destroy_mutex(t_arg *arg)
{
	int	i;

	pthread_mutex_destroy(&arg->time);
	pthread_mutex_destroy(&arg->count_mutex);
	pthread_mutex_destroy(&arg->end_mutex);
	pthread_mutex_destroy(&arg->print);
	pthread_mutex_destroy(&arg->init_thread);
	i = 0;
	while (i < arg->num_philosophers)
	{
		pthread_mutex_destroy(&arg->forks[i]);
		++i;
	}
}