/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:45:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 14:05:54 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "philo.h"

static void	do_sem(t_list *data, sem_t *key, t_switch in);

sem_t	*init_sem(char *name, t_uint value)
{
	sem_t	*ptr;

	ptr = sem_open(name, O_CREAT, 777, value);
	if (!ptr || ptr == (sem_t *)ERROR)
		exit_with_error(NULL, "sem_open");
	return (ptr);
}

void	free_sem(t_list *data, sem_t *key)
{
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

#include <stdio.h>

static void	do_sem(t_list *data, sem_t *key, t_switch in)
{
	printf("doting wait, post\n");
	if (in)
	{
		if (sem_wait(key) == ERROR)
			exit_with_error(data, "sem_wait");
	}
	else
		if (sem_post(key) == ERROR)
			exit_with_error(data, "sem_post");
}
