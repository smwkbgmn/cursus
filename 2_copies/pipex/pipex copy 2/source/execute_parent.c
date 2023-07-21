/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:26:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 04:01:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static void	wait_child(pid_t pid);
static int	get_w_exit_status(int stat);

void	parent(t_data *input, t_process ps, int *idx, int *fd_prev)
{
	close_fd(ps.fd[W]);
	if (++(*idx) < input->cnt_cmd)
	{
		*fd_prev = ps.fd[R];
		execute(input);
	}
	close_fd(ps.fd[R]);
	wait_child(ps.pid);
}

static void	wait_child(pid_t pid)
{
	int	stat;

	if (waitpid(pid, &stat, 0) == ERROR)
		exit_with_error("waitpid");
	if (get_w_exit_status(stat) == EXIT_FAILURE)
		exit_with_error(NULL);
}

static int	get_w_exit_status(int stat)
{
	return ((stat >> 8) & 0x000000ff);
}
