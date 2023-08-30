/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:09:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/30 04:22:56 by donghyu2         ###   ########.fr       */
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

// void	*malloc_erext(size_t size)
// {
// 	void	*ptr;

// 	ptr = malloc(size);
// 	if (!ptr)
// 		exit_with_error("malloc");
// 	memset(ptr, 0, size);
// 	return (ptr);
// }

void	exit_with_error(char *msg)
{
	if (msg)
		perror(msg);
	del_sem("EATING");
	del_sem("DEATH");
	del_sem("PRINT");
	del_sem("FORK_L");
	del_sem("FORK_R");
	exit(EXIT_FAILURE);
}
