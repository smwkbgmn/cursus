/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:33:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 15:13:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parent(t_process *ps, t_execute *exe, t_bool *pipe)
{
	int	exit;

	if (exe->op_seq == PIPE)
	{
		exit = execute(exe);
		close_fd(ps->fd_pipe[R]);
		close_fd(ps->fd_pipe[W]);
	}
	else
	{
		exit = wait_child(ps);
		*pipe = FALSE;
	}
	return (exit);
}

int	wait_child(t_process *ps)
{
	int	stat_loc;

	if (waitpid(ps->id, &stat_loc, 0) == ERROR)
		exit_with_error("waitpid");
	return (WEXITSTATUS(stat_loc));
}
