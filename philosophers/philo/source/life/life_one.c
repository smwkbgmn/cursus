/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:44:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/03 00:49:31 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_one(void *arg)
{
	t_list	*data;

	data = arg;
	mutex(data, FORK, ON);
	print_taking(data);
	suspend(data->program->config.delay_die);
	print_death(data);
	mutex(data, FORK, OFF);
	return (NULL);
}
