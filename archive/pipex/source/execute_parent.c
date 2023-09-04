/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:26:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/26 16:48:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static void	wait_child(t_cmd *cmd, pid_t pid);
static int	get_w_exit_status(int stat);

void	parent(t_data *input, t_process ps, int *idx, int *fd_prev)
{
	int	idx_curnt;

	idx_curnt = *idx;
	close_fd(ps.fd[W]);
	if (++(*idx) < input->cnt_cmd)
	{
		*fd_prev = ps.fd[R];
		execute(input);
	}
	close_fd(ps.fd[R]);
	wait_child(&input->cmd[idx_curnt], ps.pid);
}

static void	wait_child(t_cmd *cmd, pid_t pid)
{
	if (waitpid(pid, &cmd->exit_stat, 0) == ERROR)
		exit_with_error("waitpid");
	cmd->exit_stat = get_w_exit_status(cmd->exit_stat);
}

static int	get_w_exit_status(int stat)
{
	return ((stat >> 8) & 0x000000ff);
}
