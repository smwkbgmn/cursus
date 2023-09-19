/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:07:23 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 21:05:57 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argumet_check(t_arg *arg)
{
	if (arg->time_to_die <= 0 ||arg->num_philosophers < 1 \
	|| arg->time_to_sleep <= 0 || arg->time_to_eat <= 0 )
	{
		printf("argument error!\n");
		return (1);
	}
	return (0);
}

int	argument_five(t_arg *arg, char **av)
{
	int meals;

	meals = ft_atoi(av[5]);
	arg->num_meals = meals;
	if (meals < 1)
		return (1);
	if (arg->num_philosophers == 1)
		arg->num_meals = 0;
	return (0);
}

int	check_digit_av(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if(check_digit(av[i]) == 1)
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void	*ft_calloc(size_t c, size_t s)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(c * s);
	if (!ptr)
		return (0);
	while (i < (c * s))
	{
		((unsigned char *)ptr)[i] = 0;
		++i;
	}
	return (ptr);
}

int	init_args(t_arg *arg, int ac, char **av)
{
	if (check_digit_av(av) != 0)
		return (1);
	arg->num_philosophers = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
    arg->num_meals = 0;
	arg->start_time = current_time();
	arg->fork_flag = (int *)malloc(sizeof(int) * arg->num_philosophers);
	if(!arg->fork_flag)
		return (1);
	if(argumet_check(arg) != 0)
		return (1);
	if (ac == 6 && argument_five(arg, av) != 0)
		return (1);
	if (init_mutex(arg) != 0)
		return (1);
	return (0);
}

int	init_philo(t_philo **philo, t_arg *arg)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * arg->num_philosophers);
	if (!(*philo))
		return (1);
	while (i < arg->num_philosophers)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % arg->num_philosophers;
		(*philo)[i].last_eat_time = current_time();
		(*philo)[i].eat_count = 0;
		i++;
	}
	return (0);
}