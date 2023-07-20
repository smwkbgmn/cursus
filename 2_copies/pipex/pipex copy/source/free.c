/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:00:58 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/20 19:24:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "pipex.h"

void	free_data(t_data *input)
{
	unlink("heredoc");
	close_fd(input->fd_in);
}

void	exit_with_error(char *msg)
{
	if (msg)
		perror(msg);
	exit(EXIT_FAILURE);
}
