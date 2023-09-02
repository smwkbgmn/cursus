/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_share.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:08:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 23:35:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		set_config(int ac, char **av, t_vars *share);
static void		set_vars(t_vars *share);
static void		init_keys(t_vars *share);
static t_uint	ft_atoi(char *av);

void	init_share(int ac, char **av, t_vars *share)
{
	set_config(ac, av, share);
	set_vars(share);
	init_keys(share);
}

static void	set_config(int ac, char **av, t_vars *share)
{
	share->config.cnt_philo = ft_atoi(av[1]);
	share->config.time_die = ft_atoi(av[2]);
	share->config.time_eat = ft_atoi(av[3]);
	share->config.time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		share->config.cnt_eat = ft_atoi(av[5]);
		share->meet_all_eat = FALSE;
	}
	else
	{
		share->config.cnt_eat = -1;
		share->meet_all_eat = TRUE;
	}
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
	del_semaphore();
	share->key[0] = init_sem("EATING", share->config.cnt_philo);
	share->key[1] = init_sem("EATING_CHANGE", 1);
	share->key[2] = init_sem("DEATH", share->config.cnt_philo);
	share->key[3] = init_sem("PRINT", 1);
	share->key[4] = init_sem("FORK", share->config.cnt_philo);
	share->key[5] = init_sem("MOM", share->config.cnt_philo / 2
			+ (share->config.cnt_philo % 2 == 1));
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
