/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/10 22:34:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>

#include "minishell.h"

static int		wait_child(t_procs *ps);
static t_list	*find_next(int exit, t_list *l_exe);
static t_bool	determine_result(int exit, t_meta op_seq);

int	parent(t_procs *ps, t_list *l_exe)
{
	int		exit;

	if (((t_exe *)l_exe->content)->op_seq == PIPE)
	{
		exit = execute(l_exe->next);
		close_fd(ps->fd_pipe[W]);
		close_fd(ps->fd_pipe[R]);
		wait_child(ps);
	}
	else
	{
		exit = wait_child(ps);
		l_exe = find_next(exit, l_exe);
		if (l_exe)
			execute(l_exe);
	}
	return (exit);
}

static t_list	*find_next(int exit, t_list *l_exe)
{
	if (!l_exe)
		return (l_exe);
	else if (determine_result(exit, ((t_exe *)l_exe->content)->op_seq))
		return (find_next(exit, l_exe->next));
	else
		return (l_exe->next);
}

static t_bool	determine_result(int exit, t_meta op_seq)
{
	return ((!exit && op_seq == OR)
		|| (exit && op_seq == AND)
		|| op_seq == PIPE);
}

static int	wait_child(t_procs *ps)
{
	int	stat_loc;

	if (waitpid(ps->id, &stat_loc, 0) == ERROR)
		exit_with_error("waitpid");
	return (WEXITSTATUS(stat_loc));
}
