/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:30:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 15:10:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include "minishell.h"

static void	init_pipe(t_process *ps, t_list *l_exe);
static void	fork_process(t_process *ps);

int	execute(t_list *l_exe)
{
	static t_bool	pipe;
	t_process		ps;

	if (((t_execute *)l_exe->content)->op_seq == PIPE)
		pipe == TRUE;
	if (pipe)
		init_pipe(&ps, l_exe);
	fork_process(&ps);
	if (ps.id)
		return (parent(&ps, l_exe->content, &pipe));
	else
		return (child(&ps, l_exe->content, &pipe));
}

static void	init_pipe(t_process *ps, t_list *l_exe)
{
	t_execute	*curnt;
	t_execute	*next;

	if (pipe(ps->fd_pipe) == ERROR)
		exit_with_error("pipe");
	curnt = l_exe->content;
	next = l_exe->next->content;
	if (curnt->op_seq == PIPE && !next->cmd.fd_rd[R])
		next->cmd.fd_rd[R] = ps->fd_pipe[R];
}

static void	fork_process(t_process *ps)
{
	ps->id = fork();
	if (ps->id == ERROR)
		exit_with_error("fork");
}
