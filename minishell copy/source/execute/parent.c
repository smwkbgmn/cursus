/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 21:42:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>

#include "minishell.h"

static int		wait_child(t_procs *ps);
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
		wait_child(ps);
	}
	else
	{
		*fd_prev_out = 0;
		g_exit = wait_child(ps);
		printf("right after getting exit stat %d\n", g_exit);
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

static int	wait_child(t_procs *ps)
{
	int	stat_loc;

	if (waitpid(ps->id, &stat_loc, 0) == ERROR)
		exit_error("waitpid");
	return (WEXITSTATUS(stat_loc));
}
