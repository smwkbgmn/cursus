/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:38:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/31 00:09:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

void	free_philosophers(t_list *data, t_uint cnt);

void	free_data(t_list *data)
{
	del_semaphore(data->share->config.cnt_philo);
	free_philosophers(data, data->share->config.cnt_philo);
}

void	free_philosophers(t_list *data, t_uint cnt)
{
	t_uint	idx;
	t_list	*del;

	idx = 0;
	while (data && idx++ < cnt)
	{
		free(data->philo);
		del = data;
		data = data->next;
		free(del);
	}
}

