/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:28:56 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/27 16:36:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "so_long.h"

int	open_fd(char *name, int mode)
{
	int	fd;

	fd = open(name, mode);
	if (fd == ERROR)
		exit_with_error("open");
	return (fd);
}

void	close_fd(int fd)
{
	if (close(fd) == ERROR)
		exit_with_error("close");
}
