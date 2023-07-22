/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:27:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/22 16:04:18 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

void	redirect_pipes(t_process *ps, t_data *input, int idx, int fd_prev);
void	redirect_prev_wr_to_curnt_rd(t_process *ps, int fd_prev);

void	child(t_data *input, t_process *ps, int idx, int fd_prev)
{
	redirect_pipes(ps, input, idx, fd_prev);
	if (!input->cmd[idx].name)
	{
		error_command_not_found(*input->cmd[idx].av);
		exit_with_error(NULL);
	}
	else if (execve(input->cmd[idx].name, input->cmd[idx].av, input->env)
		== ERROR)
		exit_with_error("execve");
}

void	redirect_pipes(t_process *ps, t_data *input, int idx, int fd_prev)
{
	if (idx == 0)
	{
		redirect(input->fd_in, STDIN_FILENO);
		redirect(ps->fd[W], STDOUT_FILENO);
	}
	else
	{
		redirect_prev_wr_to_curnt_rd(ps, fd_prev);
		if (idx == input->cnt_cmd - 1)
		{
			redirect(ps->fd[R], STDIN_FILENO);
			redirect(input->fd_out, STDOUT_FILENO);
		}
		else
		{
			redirect(ps->fd[R], STDIN_FILENO);
			redirect(ps->fd[W], STDOUT_FILENO);
		}
	}
	close_fd(ps->fd[R]);
	close_fd(ps->fd[W]);
}

void	redirect_prev_wr_to_curnt_rd(t_process *ps, int fd_prev)
{
	close_fd(ps->fd[R]);
	ps->fd[R] = fd_prev;
}
