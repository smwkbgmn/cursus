/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:24:38 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/22 19:16:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking(t_thread *curnt, t_thread *next)
{
	mtx_lock(&next->philo.key_fork_set);
	if (ref_fork(next))
	{
		printf("\t\tphilo %d putting down\n", curnt->philo.name);
		mtx_unlock(&next->philo.key_fork_set);
		suspend(5);
	}
	set_fork(next, TRUE);
	print_taking_fork(curnt);
	mtx_lock(&curnt->philo.key_fork_set);
	set_fork(curnt, TRUE);
	print_taking_fork(curnt);
}

// void	taking(t_thread *curnt, t_thread *next)
// {
// 	mtx_lock(&next->philo.key_fork_set);
// 	if (ref_fork(next))
// 	{
// 		printf("\t\tphilo %d putting down\n", curnt->philo.name);
// 		mtx_unlock(&next->philo.key_fork_set);
// 		suspend(5);
// 		// mtx_lock(&next->philo.key_fork_set);
// 		taking(curnt, next);
// 	}
// 	else
// 	{
// 		set_fork(next, TRUE);
// 		print_taking_fork(curnt);
// 		mtx_lock(&curnt->philo.key_fork_set);
// 		set_fork(curnt, TRUE);
// 		print_taking_fork(curnt);
// 	}
// }

void	putting_down(t_thread *curnt, t_thread *next)
{
	set_fork(next, FALSE);
	mtx_unlock(&next->philo.key_fork_set);
	set_fork(curnt, FALSE);
	mtx_unlock(&curnt->philo.key_fork_set);
}
