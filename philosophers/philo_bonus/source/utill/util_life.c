/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:48:45 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 18:35:42 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_status(t_list *data, t_stat stat_to_change)
{
	data->philo->info.stat = stat_to_change;
}

t_stat	ref_status(t_list *data)
{
	return (data->philo->info.stat);
}
