/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 01:58:05 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 17:17:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#include "minishell.h"

int	open_fd(char *name, int option, int permit)
{
	int	fd;

	if (!permit)
		fd = open(name, option);
	else
		fd = open(name, option, permit);
	if (fd == ERROR)
	{
		ft_putstr_fd("minishell :", STDERR_FILENO);
		perror("open");
	}
	return (fd);
}

void	close_fd(int fd)
{
	if (close(fd) == ERROR)
		exit_error("close");
}

void	redirect(int fd_to_copy, int fd_to_be)
{
	if (fd_to_copy != ERROR)
	{
		if (dup2(fd_to_copy, fd_to_be) == ERROR)
			exit_error("dup2");
	}
}
