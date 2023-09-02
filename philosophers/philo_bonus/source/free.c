/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:38:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 23:48:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

static void	free_semaphore(t_vars *share);
static void	free_philosophers(t_list *data);

void	free_data(t_list *data, t_vars *share)
{
	free_semaphore(share);
	free_philosophers(data);
	del_semaphore();
}

static void	free_semaphore(t_vars *share)
{
	t_uint	cnt;

	cnt = 0;
	while (cnt < 6)
		free_sem(share->key[cnt++]);
}

static void	free_philosophers(t_list *data)
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
			free_sem(data->philo->info.key_timer);
			free(data->philo);
			del = data;
			data = data->next;
			free(del);
		}
	}
}
