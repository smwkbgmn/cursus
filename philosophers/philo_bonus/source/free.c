/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:38:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 20:37:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "philo.h"

void	free_philosophers(t_list *data, t_uint cnt);

void	free_data(t_list *data)
{
	del_semaphore();
	free_philosophers(data, data->share->config.cnt_philo);
}

void	free_philosophers(t_list *data, t_uint cnt)
{
	t_uint	idx;
	t_list	*del;
	// char	*name;

	idx = 0;
	while (data && idx++ < cnt)
	{
		// name = ft_itoa(idx);
		// sem_unlink(name);
		// free(name);
		free(data->philo);
		del = data;
		data = data->next;
		free(del);
	}
}

void	del_semaphore(void)
{
	sem_unlink("EATING");
	sem_unlink("DEATH");
	sem_unlink("PRINT");
	sem_unlink("FORK_L");
	sem_unlink("FORK_R");

	sem_unlink("1");
	sem_unlink("2");
	sem_unlink("3");
}
