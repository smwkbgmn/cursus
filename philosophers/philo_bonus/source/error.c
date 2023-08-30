/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:09:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 18:52:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "philo.h"

void	*errext(void *ptr)
{
	if (!ptr)
		exit_with_error("malloc");
	return (ptr);
}

void	exit_with_error(char *msg)
{
	if (msg)
		perror(msg);
	del_semaphore();
	exit(EXIT_FAILURE);
}
