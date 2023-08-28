/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:01:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 16:42:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

t_thread	*new_philo(t_uint idx);

void	init_data(int ac, char **av, t_list **data, t_vars *prgm)
{
	init_program(ac, av, prgm);
	init_philosophers(data, prgm);
}

void	init_program(int ac, char **av, t_vars *prgm)
{
	prgm->config.cnt_philo = ft_atoi(*(av + 1));
	prgm->config.delay_die = ft_atoi(*(av + 2));
	prgm->config.delay_eat = ft_atoi(*(av + 3));
	prgm->config.delay_sleep = ft_atoi(*(av + 4));
	if (ac == 6)
		prgm->config.cnt_eat = ft_atoi(*(av + 5));
	else
		prgm->config.cnt_eat = -1;
	prgm->philo_meet_eating = 0;
	prgm->philo_death = FALSE;
	prgm->routine[0] = &philo_think;
	prgm->routine[1] = &philo_eat;
	prgm->routine[3] = &philo_sleep;
	mtx_init(&prgm->key_eating);
	mtx_init(&prgm->key_death);
	mtx_init(&prgm->key_print);
}

void	init_philosophers(t_list **data, t_vars *prgm)
{
	t_uint		idx;
	t_list		*list_new;
	t_thread	*thread;

	idx = 1;
	while (idx <= prgm->config.cnt_philo)
	{
		thread = new_philo(idx);
		list_new = ft_lstnew(thread, prgm);
		ft_lstadd(data, list_new);
		idx++;
	}
}

t_thread	*new_philo(t_uint idx)
{
	t_thread	*thread;

	thread = malloc(sizeof(t_thread));
	thread->philo.name = idx;
	thread->philo.stat = STARVE;
	thread->philo.eating = 0;
	mtx_init(&thread->philo.key_stat);
	mtx_init(&thread->philo.key_fork);
	mtx_init(&thread->philo.key_timer);
	return (thread);
}
