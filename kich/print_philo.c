/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichan <kichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:09:02 by kichan            #+#    #+#             */
/*   Updated: 2023/09/19 23:09:18 by kichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_philo(t_arg *arg, int id, char *msg)
{
	unsigned long long	now;

	pthread_mutex_lock(&(arg->print));
	now = current_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(arg->end_mutex));
	if (!(arg->end_flag))
	{
		printf("%lld %d %s\n", now - arg->start_time, id + 1, msg);
		// pthread_mutex_unlock(&(arg->end_mutex));
	}
	pthread_mutex_unlock(&(arg->end_mutex));
	if (ft_strncmp(msg, "is died", 7) == 0)
		return (0);
	pthread_mutex_unlock(&(arg->print));
	return (0);
}
