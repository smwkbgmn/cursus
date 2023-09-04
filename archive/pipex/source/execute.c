/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:45:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/25 19:46:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static void	fork_process(t_process *ps);
static void	init_pipe(t_process *ps);
static void	init_process(t_process *ps);

void	execute(t_data *input)
{
	t_process	ps;
	static int	idx;
	static int	fd_prev;

	fork_process(&ps);
	if (!ps.pid)
		child(input, &ps, idx, fd_prev);
	else
		parent(input, ps, &idx, &fd_prev);
}

static void	fork_process(t_process *ps)
{
	init_pipe(ps);
	init_process(ps);
}

static void	init_pipe(t_process *ps)
{
	if (pipe(ps->fd) == ERROR)
		exit_with_error("pipe");
}

static void	init_process(t_process *ps)
{
	ps->pid = fork();
	if (ps->pid == ERROR)
		exit_with_error("fork");
}
