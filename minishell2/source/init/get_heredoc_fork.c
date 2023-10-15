/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:43:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 17:23:17 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "minishell.h"

static void	handle(pid_t pid);
static void	do_work(char *fname, char *delim);

void	fork_heredoc(char *fname, char *delim)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
		exit_error("fork");
	if (pid)
		handle(pid);
	else
		do_work(fname, delim);
}

static void	handle(pid_t pid)
{
	int	stat_loc;

	signal(SIGINT, SIG_IGN);
	if (waitpid(pid, &stat_loc, 0) == ERROR)
		exit_error("waitpid");
	g_exit = WEXITSTATUS(stat_loc);
}

static void	do_work(char *fname, char *delim)
{
	int	fd;

	init_signal(HEREDOC);
	fd = open_fd(fname, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	write_heredoc(fd, delim);
	close_fd(fd);
	exit(g_exit);
}
