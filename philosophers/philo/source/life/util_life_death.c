/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:55:37 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 03:15:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	config_can_not_continue(t_config *config)
{
	return (config->cnt_philo == 1
		|| config->delay_die == 0
		|| config->cnt_eat == 0);
}

void	set_death(t_vars *prgm)
{
	mtx_lock(&prgm->key_death);
	prgm->philo_death = TRUE;
	mtx_unlock(&prgm->key_death);
}

t_bool	ref_death(t_vars *prgm)
{
	t_bool	result;

	mtx_lock(&prgm->key_death);
	result = prgm->philo_death;
	mtx_unlock(&prgm->key_death);
	return (result);
}
