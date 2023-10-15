/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 16:56:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>

#include "minishell.h"

static void		wait_child(t_procs *ps, t_bool flag);
static t_list	*find_next(t_list *l_exe);
static t_bool	determine_result(t_meta op_seq);

void	parent(t_procs *ps, t_list *l_exe, int *fd_prev_out)
{
	if (((t_exe *)l_exe->content)->op_seq == PIPE)
	{
		close_fd(ps->fd_pipe[W]);
		*fd_prev_out = ps->fd_pipe[R];
		execute(l_exe->next);
		close_fd(ps->fd_pipe[R]);
		wait_child(ps, (l_exe->next == NULL));
	}
	else
	{
		*fd_prev_out = 0;
		wait_child(ps, (l_exe->next == NULL));
		l_exe = find_next(l_exe);
		if (l_exe)
			execute(l_exe);
	}
}

static t_list	*find_next(t_list *l_exe)
{
	if (!l_exe)
		return (l_exe);
	else if (determine_result(((t_exe *)l_exe->content)->op_seq))
		return (find_next(l_exe->next));
	else
		return (l_exe->next);
}

static t_bool	determine_result(t_meta op_seq)
{
	return ((!g_exit && op_seq == OR)
		|| (g_exit && op_seq == AND)
		|| op_seq == PIPE);
}

static void	wait_child(t_procs *ps, t_bool flag)
{
	int	stat_loc;

	signal(SIGINT, SIG_IGN);
	if (waitpid(ps->id, &stat_loc, 0) == ERROR)
		exit_error("waitpid");
	if (flag)
		g_exit = WEXITSTATUS(stat_loc);
	if (WIFSIGNALED(stat_loc))
		g_exit = 128 + WTERMSIG(stat_loc);
}
