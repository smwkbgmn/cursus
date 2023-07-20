/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:22:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 04:04:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "pipex.h"

void	init_fd(t_data *input, int ac, char **av)
{
	if (input->heredoc)
	{
		input->fd_in = open_fd("heredoc", O_RDONLY, 0);
		input->fd_out = open_fd(av[ac - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		input->fd_in = open_fd(av[1], O_RDONLY, 0);
		input->fd_out = open_fd(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
}
