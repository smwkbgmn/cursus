/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:45:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 04:22:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_sem(sem_t *key, t_switch in);

sem_t	*init_sem(char *name, t_uint value)
{
	sem_t	*ptr;

	// ptr = sem_open(name, O_CREAT | O_EXCL, 700, value);
	ptr = sem_open(name, 0x00000200 | 0x00000800, 777, value);
	// if (*ptr == ERROR)
	if (ptr == (sem_t *)ERROR)
		exit_with_error("sem_open");
	return (ptr);
}

void	del_sem(char *name)
{
	if (sem_unlink(name) == ERROR)
		exit_with_error("sem_unlink");
}

void	semaphore(t_list *data, t_keyname name, t_switch in)
{
	do_sem(data->share->key[name], in);
}

static void	do_sem(sem_t *key, t_switch in)
{
	if (in)
	{
		if (sem_wait(key) == ERROR)
			exit_with_error("sem_wait");
	}
	else
		if (sem_post(key) == ERROR)
			exit_with_error("sem_post");
}
