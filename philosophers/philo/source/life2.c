/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:24:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/21 22:17:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking(t_thread *curnt, t_thread *prev)
{
	mtx_lock(&curnt->philo.key_fork_set);
	set_fork(curnt, TRUE);
	if (ref_fork(prev))
	{
		set_fork(curnt, FALSE);
		mtx_unlock(&curnt->philo.key_fork_set);
		suspend(10);
		taking(curnt, prev);
	}
	mtx_lock(&prev->philo.key_fork_set);
	set_fork(prev, TRUE);
	print_taking_fork(curnt);
	print_taking_fork(curnt);
}

void	putting_down(t_thread *curnt, t_thread *prev)
{
	set_fork(prev, FALSE);
	mtx_unlock(&prev->philo.key_fork_set);
	set_fork(curnt, FALSE);
	mtx_unlock(&curnt->philo.key_fork_set);
}
