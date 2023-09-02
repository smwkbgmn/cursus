/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:41:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 14:13:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include "philo.h"

static void	init_process(pid_t *id);
static void	parent(t_list *data, t_uint *idx);
static void	child(t_list *data);
static void	wait_child(t_list *data);

void	start_life(t_list *data)
{
	static t_uint	idx;

	init_process(&data->philo->id);
	if (data->philo->id)
		parent(data, &idx);
	else
		child(data);
}

static void	init_process(pid_t *id)
{
	*id = fork();
	if (*id == ERROR)
		exit_with_error("fork");
}

static void	parent(t_list *data, t_uint *idx)
{
	if (++(*idx) < data->share->config.cnt_philo)
		start_life(data->next);
	else if (data->share->config.cnt_philo > 1)
	{
		suspend(50);
		start_monitor(data);
		join_monitor(data);
	}
	wait_child(data);
}

static void	child(t_list *data)
{
	if (data->share->config.cnt_philo == 1)
		life_one(data);
	else
		life(data);
}

static void	wait_child(t_list *data)
{
	if (waitpid(data->philo->id, NULL, 0) == ERROR)
		exit_with_error("waitpid");
}
