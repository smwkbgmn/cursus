/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:45:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 01:06:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

#include "philo.h"

static void	do_sem(t_list *data, sem_t *key, t_switch in);

sem_t	*init_sem(char *name, t_uint value)
{
	sem_t	*ptr;

	// ptr = sem_open(name, O_CREAT | O_EXCL, 777, value);
	ptr = sem_open(name, O_CREAT, 777, value);
	printf("init: %p\n", ptr);
	if (ptr == (sem_t *)ERROR)
		exit_with_error(NULL, "sem_open");
	return (ptr);
}

void	free_sem(t_list *data, sem_t *key)
{
	printf("free: %p\n", key);
	if (sem_close(key) != SUCCESS)
		exit_with_error(data, "sem_close");
}

void	semaphore(t_list *data, t_keyname name, t_switch in)
{
	if (name < 5)
		do_sem(data, data->share->key[name], in);
	else
		do_sem(data, data->philo->info.key_timer, in);
}

static void	do_sem(t_list *data, sem_t *key, t_switch in)
{
	if (in)
	{
		if (sem_wait(key) == ERROR)
			exit_with_error(data, "sem_wait");
	}
	else
		if (sem_post(key) == ERROR)
			exit_with_error(data, "sem_post");
}
