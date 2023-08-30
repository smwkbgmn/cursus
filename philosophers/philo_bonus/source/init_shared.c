/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shared.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:08:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 13:10:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

static void		set_config(int ac, char **av, t_vars *share);
static void		set_vars(t_vars *share);
static void		init_keys(t_vars *share);
static t_uint	ft_atoi(char *av);

void	init_share(int ac, char **av, t_vars **share)
{
	*share = errext(malloc(sizeof(t_vars)));
	set_config(ac, av, *share);
	set_vars(*share);
	init_keys(*share);
}

static void	set_config(int ac, char **av, t_vars *share)
{
	share->config.cnt_philo = ft_atoi(av[1]);
	share->config.time_die = ft_atoi(av[2]);
	share->config.time_eat = ft_atoi(av[3]);
	share->config.time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		share->config.cnt_eat = ft_atoi(av[5]);
	else
	share->config.cnt_eat = -1;
}

static void	set_vars(t_vars *share)
{
	share->cnt_done_eat = 0;
	share->death = FALSE;
	share->routine[0] = &philo_think;
	share->routine[1] = &philo_eat;
	share->routine[3] = &philo_sleep;
}

static void	init_keys(t_vars *share)
{
	share->key[0] = init_sem("EATING", 1);
	share->key[1] = init_sem("DEATH", 1);
	share->key[2] = init_sem("PRINT", 1);
	share->key[3] = init_sem("FORK_L", share->config.cnt_philo / 2);
	share->key[4] = init_sem("FORK_R", share->config.cnt_philo / 2);
}

static t_uint	ft_atoi(char *av)
{
	t_uint	num;

	num = 0;
	while (*av)
	{
		num = num * 10 + (*av - '0');
		av++;
	}
	return (num);
}
