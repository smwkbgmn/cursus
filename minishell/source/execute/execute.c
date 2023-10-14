/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:30:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 17:08:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"

static void		init_process(t_procs *ps, t_exe *exe, int fd_prev_out);
static void		init_pipe(t_procs *ps);
static void		fork_process(t_procs *ps);
static t_bool	is_pipemode(t_exe *exe, int fd_prev_out);

void	execute(t_list *l_exe)
{
	t_procs		ps;
	static int	fd_prev_out;

	if (is_builtin(((t_exe *)l_exe->content)->cmd.path)
		&& !is_pipemode(l_exe->content, fd_prev_out))
		execute_builtin(l_exe->content, FALSE);
	else
	{
		init_process(&ps, l_exe->content, fd_prev_out);
		if (ps.id)
			parent(&ps, l_exe, &fd_prev_out);
		else
			child(&ps, l_exe->content, fd_prev_out);
	}
}

static void	init_process(t_procs *ps, t_exe *exe, int fd_prev_out)
{
	ft_memset(ps, 0, sizeof(t_procs));
	if (exe->op_seq == PIPE || fd_prev_out)
		init_pipe(ps);
	fork_process(ps);
}

static void	init_pipe(t_procs *ps)
{
	if (pipe(ps->fd_pipe) == ERROR)
		exit_error("pipe");
}

static void	fork_process(t_procs *ps)
{
	ps->id = fork();
	if (ps->id == ERROR)
		exit_error("fork");
}

static t_bool	is_pipemode(t_exe *exe, int fd_prev_out)
{
	return (exe->op_seq == PIPE || fd_prev_out);
}
