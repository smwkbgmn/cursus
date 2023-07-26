/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:22:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/22 22:50:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "pipex.h"

void	init_file(t_data *input, int ac, char **av)
{
	if (input->heredoc)
	{
		input->fd_in = open_fd("heredoc", O_RDONLY, 0, R);
		input->fd_out = open_fd(av[ac - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644, W);
	}
	else
	{
		input->fd_in = open_fd(av[1], O_RDONLY, 0, R);
		input->fd_out = open_fd(av[ac - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644, W);
	}
}
