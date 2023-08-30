/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 18:34:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking(t_list *data)
{
	semaphore(data, FORK_L, IN);
	print_taking(data);
	semaphore(data, FORK_R, IN);
	print_taking(data);
}

void	putting_down(t_list *data)
{
	semaphore(data, FORK_R, OUT);
	semaphore(data, FORK_L, OUT);
}
