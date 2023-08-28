/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:44:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/29 04:34:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*life_one(void *arg)
{
	t_list	*data;

	data = arg;
	// if (data->program->config.delay_die > 0)
	// {
		print_taking(data);
		suspend(data->program->config.delay_die);
	// }
	print_death(data);
	return (NULL);
}
