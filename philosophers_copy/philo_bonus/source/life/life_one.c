/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:37:36 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/31 00:41:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	life_one(t_list *data)
{
	print_taking(data);
	suspend(data->share->config.time_die);
	print_death(data);
}
