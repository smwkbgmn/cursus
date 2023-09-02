/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:38:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 14:06:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

void	free_semaphore(t_list *data, t_vars *share);
void	free_philosophers(t_list *data);

void	free_data(t_list *data, t_vars *share)
{
	free_semaphore(data, share);
	free_philosophers(data);
	del_semaphore(data);
}

void	free_semaphore(t_list *data, t_vars *share)
{
	free_sem(data, share->key[0]);
	free_sem(data, share->key[1]);
	free_sem(data, share->key[2]);
	free_sem(data, share->key[3]);
	free_sem(data, share->key[4]);
}

void	free_philosophers(t_list *data)
{
	t_uint	cnt;
	t_uint	idx;
	t_list	*del;

	if (data)
	{
		idx = 0;
		cnt = data->share->config.cnt_philo;
		while (idx++ < cnt)
		{
			free_sem(data, data->philo->info.key_timer);
			free(data->philo);
			del = data;
			data = data->next;
			free(del);
		}
	}
}

void	del_semaphore(t_list *data)
{
	t_uint	idx;
	char	*name;

	sem_unlink("EATING");
	sem_unlink("DEATH");
	sem_unlink("PRINT");
	sem_unlink("FORK_L");
	sem_unlink("FORK_R");

	if (data)
	{
		idx = 0;
		while (idx < data->share->config.cnt_philo)
		{
			name = ft_itoa(idx + 1);
			sem_unlink(name);
			free(name);
			idx++;
		}
	}
}
