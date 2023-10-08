/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 15:11:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_pipe(t_process *ps, t_execute *exe);

int	child(t_process *ps, t_execute *exe, t_bool *pipe)
{
	if (*pipe)
		redirect_pipe(ps, exe);
	execve(exe->cmd.name, exe->cmd.av, NULL);
}

static void	redirect_pipe(t_process *ps, t_execute *exe)
{
	int	fd[2];

	fd[R] = exe->cmd.fd_rd[R] + (ps->fd_pipe[R] * (exe->cmd.fd_rd[R] == 0));
	fd[W] = exe->cmd.fd_rd[W] + (ps->fd_pipe[W] * (exe->cmd.fd_rd[W] == 0));
	redirect(fd[R], STDIN_FILENO);
	redirect(fd[W], STDOUT_FILENO);
	close_fd(ps->fd_pipe[R]);
	close_fd(ps->fd_pipe[W]);
}
