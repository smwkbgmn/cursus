/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:07:38 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 23:10:50 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_philo(t_arg *arg, t_philo *philo)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&(arg->init_thread));
	while (i < arg->num_philosophers)
	{	
		philo[i].last_eat_time = current_time();
		if (pthread_create(&(philo[i].thread), NULL, thread_start, &(philo[i])))
			return (1);
		i++;
	}
	pthread_mutex_unlock(&(arg->init_thread));
	monitor(arg, philo);
	i = 0;
	while (i < arg->num_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		++i;
	}
	return (0);
}

void	*thread_start(void *argv)
{
	t_arg		*arg;
	t_philo		*philo;

	philo = argv;
	arg = philo->arg;
	pthread_mutex_lock(&(arg->init_thread));
	pthread_mutex_unlock(&(arg->init_thread));
	if (philo->id % 2 == 1)
		sleep_even(arg);
	if (arg->num_philosophers%2 == 1 && (philo->id == arg->num_philosophers-1))
	{	
		sleep_even(arg);
		sleep_even(arg);
	}
	while (!arg->end_flag)
	{
		get_fork_eating(arg, philo);
		if (arg->num_philosophers == 1)
			spend_time((unsigned long long)arg->time_to_sleep, arg);
		pthread_mutex_lock(&(arg->count_mutex));
		if (arg->num_meals == philo->eat_count)
		{
			arg->end_meal_count++;
			break ;
		}
		pthread_mutex_unlock(&(arg->count_mutex));
		print_philo(arg, philo->id, "is sleeping");
		spend_time((unsigned long long)arg->time_to_sleep, arg);
		print_philo(arg, philo->id, "is thinking");
	}
	return (0);
}

int	get_fork_eating(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&(arg->forks[philo->left]));
	arg->fork_flag[philo->id % arg->num_philosophers] = 1;
	print_philo(arg, philo->id, "has taken a fork");
	if (arg->num_philosophers != 1)
	{
		pthread_mutex_lock(&(arg->forks[philo->right]));
		arg->fork_flag[(philo->id + 1) % arg->num_philosophers] = 1;
		print_philo(arg, philo->id, "has taken a fork");
		print_philo(arg, philo->id, "is eating");
		pthread_mutex_lock(&(arg->time));
		philo->last_eat_time = current_time();
		pthread_mutex_unlock(&(arg->time));
		philo->eat_count = philo->eat_count + 1;
		spend_time((unsigned long long)arg->time_to_eat, arg);
		arg->fork_flag[(philo->id + 1) % arg->num_philosophers] = 0;
		pthread_mutex_unlock(&(arg->forks[philo->right]));
	}
	arg->fork_flag[philo->id % arg->num_philosophers] = 0;
	pthread_mutex_unlock(&(arg->forks[philo->left]));
	return (0);
}

void	monitor(t_arg *arg, t_philo *philo)
{
	int			i;
	long long	now;

	pthread_mutex_lock(&(arg->end_mutex));
	while (!arg->end_flag)
	{
		if ((arg->num_meals != 0) && (arg->num_philosophers == arg->end_flag) )
		{
			arg->end_flag = 1;
			pthread_mutex_unlock(&(arg->end_mutex));
			break ;
		}
		i = 0;
		while (i < arg->num_philosophers)
		{
			if (arg->end_flag)
			{
				pthread_mutex_unlock(&(arg->end_mutex));
				break;
			}
			now = current_time();
			pthread_mutex_lock(&(arg->time));
			if ((now - philo[i].last_eat_time) >= arg->time_to_die)
			{
				pthread_mutex_unlock(&(arg->time));
				print_philo(arg, i, "is died");
				arg->end_flag = 1;
				pthread_mutex_unlock(&(arg->end_mutex));
				pthread_mutex_unlock(&(arg->print));
				break ;
			}
			pthread_mutex_unlock(&(arg->end_mutex));
			pthread_mutex_unlock(&(arg->time));
			i++;
		}
	}
}