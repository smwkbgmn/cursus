/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 22:36:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include "minishell.h"

static int	wait_child(t_process *ps);

int	parent(t_process *ps, t_list *l_exe)
{
	int			exit;

	if (((t_execute *)l_exe->content)->op_seq == PIPE)
	{
		// printf("\tcheck 1\n");
		close_fd(ps->fd_pipe[W]);
		exit = execute(l_exe->next);
		close_fd(ps->fd_pipe[R]);
		wait_child(ps);
	}
	else
	{
		// printf("\tcheck 2\n");
		exit = wait_child(ps);
	}
	return (exit);
}

static int	wait_child(t_process *ps)
{
	int	stat_loc;

	if (waitpid(ps->id, &stat_loc, 0) == ERROR)
		exit_with_error("waitpid");
	return (WEXITSTATUS(stat_loc));
}
