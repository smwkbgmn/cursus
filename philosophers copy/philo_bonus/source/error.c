/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:09:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/02 14:10:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
		printf("Error : %s\n", msg);
	del_semaphore();
	exit(EXIT_FAILURE);
}
