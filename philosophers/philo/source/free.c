/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:22:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 02:08:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

void	free_keys(t_mutex *key);
void	free_keys_philo(t_list *data, t_uint cnt);
void	free_philosophers(t_list *data, t_uint cnt);

void	free_data(t_list *data, t_vars *prgm)
{
	free_keys(&prgm->key[0]);
	if (data)
	{
		free_keys_philo(data, prgm->config.cnt_philo);
		free_philosophers(data, data->program->config.cnt_philo);
	}
}

void	free_keys(t_mutex *key)
{
	t_uint	idx;

	idx = 0;
	while (idx < 3)
		mtx_free(&key[idx++]);
}

void	free_keys_philo(t_list *data, t_uint cnt)
{
	t_uint	idx;

	idx = 0;
	while (idx++ < cnt && data)
	{
		free_keys(&data->thread->philo.key[0]);
		data = data->next;
	}
}

void	free_philosophers(t_list *data, t_uint cnt)
{
	t_uint	idx;
	t_list	*del;

	idx = 0;
	while (data && idx++ < cnt)
	{
		free(data->thread);
		del = data;
		data = data->next;
		free(del);
	}
}
