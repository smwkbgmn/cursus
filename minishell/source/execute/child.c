/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/10 20:30:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static void	redirect_pipe(t_procs *ps, t_exe *exe);

int	child(t_procs *ps, t_exe *exe)
{
	redirect_pipe(ps, exe);
	execve(exe->cmd.path, exe->cmd.av, NULL);
	return (EXIT_SUCCESS);
}

static void	redirect_pipe(t_procs *ps, t_exe *exe)
{
	int	fd[2];

	if (exe->op_seq == PIPE)
	{
		fd[R] = exe->cmd.fd_rd[R] + (ps->fd_pipe[R] * (exe->cmd.fd_rd[R] == 0));
		fd[W] = exe->cmd.fd_rd[W] + (ps->fd_pipe[W] * (exe->cmd.fd_rd[W] == 0));
		redirect(fd[R], STDIN_FILENO);
		redirect(fd[W], STDOUT_FILENO);
		close_fd(ps->fd_pipe[R]);
		close_fd(ps->fd_pipe[W]);
	}
	else
	{
		if (exe->cmd.fd_rd[R])
		{
			redirect(exe->cmd.fd_rd[R], STDIN_FILENO);
			close_fd(exe->cmd.fd_rd[R]);
		}
		if (exe->cmd.fd_rd[W])
		{
			redirect(exe->cmd.fd_rd[W], STDOUT_FILENO);
			close_fd(exe->cmd.fd_rd[W]);
		}
	}
}
