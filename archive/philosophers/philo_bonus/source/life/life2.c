/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/03 01:20:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking(t_list *data)
{
	semaphore(data, MOM, IN);
	semaphore(data, FORK, IN);
	print_taking(data);
	semaphore(data, FORK, IN);
	print_taking(data);
}

void	putting_down(t_list *data)
{
	semaphore(data, FORK, OUT);
	semaphore(data, FORK, OUT);
	semaphore(data, MOM, OUT);
}
