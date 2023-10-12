/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:21:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 19:05:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear(t_list *l_exe);
static void	clear_argument(char *path, char **argv);
static void	clear_redirection(int fd[2]);
static void	clear_heredoc(char *fname);

void	free_data(t_list **l_exe)
{
	clear(*l_exe);
	ft_lstclear(l_exe, &ft_free);
}

static void	clear(t_list *l_exe)
{
	t_exe	*exe;

	while (l_exe)
	{
		exe = l_exe->content;
		clear_argument(exe->cmd.path, exe->cmd.av);
		clear_redirection(exe->cmd.fd_rd);
		clear_heredoc(exe->cmd.fname_heredoc);
		l_exe = l_exe->next;
	}
}

static void	clear_argument(char *path, char **argv)
{
	int	ptr;

	ptr = 0;
	while (argv[ptr])
		ft_free(argv[ptr++]);
	ft_free(argv);
	ft_free(path);
}

static void	clear_redirection(int fd[2])
{
	if (fd[R] && fd[R] != ERROR)
		close_fd(fd[R]);
	if (fd[W] && fd[W] != ERROR)
		close_fd(fd[W]);
}

static void	clear_heredoc(char *fname)
{
	if (fname)
		unlink(fname);
}
