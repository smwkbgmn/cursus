/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:18:36 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/22 22:31:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "pipex.h"

void	*catcher(void *ptr)
{
	if (!ptr)
		exit_with_error("malloc");
	return (ptr);
}

void	write_command_not_found(char *av_name)
{
	write(STDERR_FILENO, "command not found: ", 19);
	write(STDERR_FILENO, av_name, ft_strlen(av_name));
	write(STDERR_FILENO, "\n", 1);
}

void	exit_with_error(char *msg)
{
	if (msg)
		perror(msg);
	exit(EXIT_FAILURE);
}
