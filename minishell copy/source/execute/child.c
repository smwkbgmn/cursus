/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:52 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 12:54:33 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static void	redirect_pipe(t_procs *ps, int fd_prev, t_meta op_seq);
static void	redirect_prev_out_to_curnt_rd(t_procs *ps, int fd_prev);
static void	redirect_file(int fd_rd[2]);
static void	valid_command(t_exe *exe);

void	child(t_procs *ps, t_exe *exe, int fd_prev)
{
	extern char	**environ;

	redirect_pipe(ps, fd_prev, exe->op_seq);
	redirect_file(exe->cmd.fd_rd);
	valid_command(exe);
	execve(exe->cmd.path, exe->cmd.av, environ);
}

static void	redirect_pipe(t_procs *ps, int fd_prev, t_meta op_seq)
{
	if (ps->fd_pipe[R] && ps->fd_pipe[W])
	{
		if (fd_prev)
		{
			redirect_prev_out_to_curnt_rd(ps, fd_prev);
			redirect(ps->fd_pipe[R], STDIN_FILENO);
		}
		if (op_seq == PIPE)
			redirect(ps->fd_pipe[W], STDOUT_FILENO);
		close_fd(ps->fd_pipe[R]);
		close_fd(ps->fd_pipe[W]);
	}
}

static void	redirect_prev_out_to_curnt_rd(t_procs *ps, int fd_prev)
{
	close_fd(ps->fd_pipe[R]);
	ps->fd_pipe[R] = fd_prev;
}

static void	redirect_file(int fd_rd[2])
{
	if (fd_rd[R])
		redirect(fd_rd[R], STDIN_FILENO);
	if (fd_rd[W])
		redirect(fd_rd[W], STDOUT_FILENO);
}

static void	valid_command(t_exe *exe)
{
	if (!exe->cmd.path)
		exit_error_usr(127);
	if (ft_strncmp(exe->cmd.path, "null", 4) == MATCH)
		exit_error_usr(126);
	if (exe->cmd.fd_rd[R] == ERROR || exe->cmd.fd_rd[W] == ERROR)
		exit_error_usr(1);
}
