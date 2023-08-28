/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:22:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 14:56:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

void	free_program(t_list *data);
void	free_philosophers(t_list *data, t_uint cnt);

void	free_data(t_list *data)
{
	free_program(data);
	free_philosophers(data, data->program->config.cnt_philo);
}

void	free_program(t_list *data)
{
	mtx_free(&data->program->key_eating);
	mtx_free(&data->program->key_death);
	mtx_free(&data->program->key_print);
}

void	free_philosophers(t_list *data, t_uint cnt)
{
	t_uint	idx;
	t_list	*del;

	idx = 1;
	while (idx++ <= cnt)
	{
		mtx_free(&data->thread->philo.key_stat);
		mtx_free(&data->thread->philo.key_fork);
		mtx_free(&data->thread->philo.key_timer);
		free(data->thread);
		del = data;
		data = data->next;
		free(del);
	}
}
