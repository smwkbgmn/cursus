/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:30:54 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/05 14:22:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

#include "minishell.h"

int	execute(t_execute *exe)
{
	fork_process(exe->l_procs->content);
	if (((t_process *)exe->l_procs->content)->id)
		return (parent(exe));
	else
		return (child(exe));
}

void	fork_process(t_process *procs)
{
	procs->id = fork();
	if (procs->id == ERROR)
		exit_with_error("fork");
	init_pipe(procs);
}

void	init_pipe(t_process *procs)
{
	if (pipe(procs->fd) == ERROR)
		exit_with_error("pipe");
}

void	parent(t_execute *exe)
{
	t_token		*token;
	t_process	*procs;

	token = exe->l_token->content;
	procs = exe->l_procs->content;
	if (token->type == PIPE)
		return (execute(exe->next));
	else
		return (waitpid(procs));
}

void	child(t_list *exe)
{

}

int	wait_child(t_process *procs)
{
	int	stat_loc;

	if (waitpid(procs->id, &stat_loc, 0) == ERROR)
		exit_with_error("waitpid");
	return (WEXITSTATUS(stat_loc));
}
