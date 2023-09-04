/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:45:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 23:38:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

#include "philo.h"

static void	do_sem(sem_t *key, t_switch in);

sem_t	*init_sem(char *name, t_uint value)
{
	sem_t	*ptr;

	ptr = sem_open(name, O_CREAT, 777, value);
	if (!ptr || ptr == (sem_t *)ERROR)
		exit_with_error("sem_open");
	return (ptr);
}

void	free_sem(sem_t *key)
{
	if (sem_close(key) != SUCCESS)
		exit_with_error("sem_close");
}

void	del_semaphore(void)
{
	t_uint	idx;
	char	*name;

	sem_unlink("EATING");
	sem_unlink("EATING_CHANGE");
	sem_unlink("DEATH");
	sem_unlink("PRINT");
	sem_unlink("FORK");
	sem_unlink("MOM");
	idx = 0;
	while (idx < 200)
	{
		name = ft_itoa(idx);
		sem_unlink(name);
		free(name);
		idx++;
	}
}

void	semaphore(t_list *data, t_keyname name, t_switch in)
{
	if (name < 6)
		do_sem(data->share->key[name], in);
	else
		do_sem(data->philo->info.key_timer, in);
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
