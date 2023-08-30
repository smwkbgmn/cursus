/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 04:55:07 by donghyu2         ###   ########.fr       */
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

// void	taking(t_list *data)
// {
// 	semaphore(data, FORK, IN);
// 	if (data->philo->info.name % 2 == 0
// 		&& ref_status(data->prev) == STARVE)
// 	{
// 		semaphore(data, FORK, OUT);
// 		suspend(10);
// 		semaphore(data, FORK, IN);
// 	}
// 	print_taking(data);
// 	semaphore(data, FORK, IN);
// 	print_taking(data);
// }

// void	putting_down(t_list *data)
// {
// 	semaphore(data, FORK, OUT);
// 	semaphore(data, FORK, OUT);
// }
