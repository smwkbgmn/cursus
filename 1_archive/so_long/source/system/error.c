/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:38:13 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/29 01:31:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "so_long.h"

void	*catcher(void *ptr)
{
	if (!ptr)
		exit_with_error("malloc");
	return (ptr);
}

void	exit_with_error(char *msg)
{
	if (msg)
		perror(msg);
	system("leaks so_long");
	exit(EXIT_FAILURE);
}

void	write_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
}
