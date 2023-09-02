/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:16:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 14:25:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_list *data, pthread_t *id, void *function)
{
	if (pthread_create(id, NULL, function, data) != SUCCESS)
		exit_with_error("pthread_create");
}

void	join_thread(pthread_t *id)
{
	if (pthread_join(*id, NULL) != SUCCESS)
		exit_with_error("pthread_join");
}

void	detach_thread(pthread_t *id)
{
	if (pthread_detach(*id) != SUCCESS)
		exit_with_error("pthread_detach");
}
