/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 03:40:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 04:17:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		set_config(int ac, char **av, t_vars *prgm);
static void		set_program(t_vars *prgm);
static t_uint	ft_atoi(char *av);

t_bool	init_program(int ac, char **av, t_vars *prgm)
{
	set_config(ac, av, prgm);
	set_program(prgm);
	return (init_keys(&prgm->key[0]));
}

static void	set_config(int ac, char **av, t_vars *prgm)
{
	prgm->config.cnt_philo = ft_atoi(av[1]);
	prgm->config.delay_die = ft_atoi(av[2]);
	prgm->config.delay_eat = ft_atoi(av[3]);
	prgm->config.delay_sleep = ft_atoi(av[4]);
	if (ac == 6)
		prgm->config.cnt_eat = ft_atoi(av[5]);
	else
		prgm->config.cnt_eat = -1;
}

static void	set_program(t_vars *prgm)
{
	prgm->philo_meet_eating = 0;
	prgm->philo_death = FALSE;
	prgm->routine[0] = &philo_think;
	prgm->routine[1] = &philo_eat;
	prgm->routine[3] = &philo_sleep;
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
