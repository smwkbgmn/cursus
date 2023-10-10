/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:30:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/10 21:38:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_pipe(t_procs *ps, t_list *l_exe);
static void	assign_curnt_wr_to_next_rd(int curnt_wr, t_exe *exe_next);
static void	fork_process(t_procs *ps);

int	execute(t_list *l_exe)
{
	t_procs		ps;

	if (((t_exe *)l_exe->content)->op_seq == PIPE)
		init_pipe(&ps, l_exe);
	fork_process(&ps);
	if (ps.id)
		return (parent(&ps, l_exe));
	else
		return (child(&ps, l_exe->content));
}

static void	init_pipe(t_procs *ps, t_list *l_exe)
{
	if (pipe(ps->fd_pipe) == ERROR)
		exit_with_error("pipe");
	assign_curnt_wr_to_next_rd(ps->fd_pipe[R], l_exe->next->content);
}

static void	assign_curnt_wr_to_next_rd(int curnt_wr, t_exe *exe_next)
{
	if (!exe_next->cmd.fd_rd[R])
		exe_next->cmd.fd_rd[R] = curnt_wr;
}

static void	fork_process(t_procs *ps)
{
	ps->id = fork();
	if (ps->id == ERROR)
		exit_with_error("fork");
}
