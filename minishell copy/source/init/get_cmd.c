/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/12 18:40:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static t_exe	*init_exe(int argc);
static void		assign_av(t_exe *exe, int argc, t_list *l_token);
static void		assign_redirect(t_exe *exe, t_meta type, char *name);
static void		apply_redirect(t_exe *exe, t_exe *tmp);

t_exe	*get_command(t_list *l_token)
{
	static int	argc;
	t_exe		*exe;
	t_exe		tmp_rd;

	if (!l_token || is_sequence(l_token))
		exe = init_exe(argc);
	else
	{
		if (ref_type(l_token) == NONE)
		{
			argc++;
			exe = get_command(l_token->next);
			assign_av(exe, --argc, l_token);
		}
		else
		{
			ft_memset(&tmp_rd, 0, sizeof(t_exe));
			assign_redirect(&tmp_rd, ref_type(l_token),
				((t_token *)l_token->next->content)->str);
			exe = get_command(l_token->next->next);
			apply_redirect(exe, &tmp_rd);
		}
	}
	return (exe);
}

static t_exe	*init_exe(int argc)
{
	t_exe	*exe;

	if (argc)
	{
		exe = calloc_erx(1, sizeof(t_exe));
		exe->cmd.av = calloc_erx(argc + 1, sizeof(char *));
	}
	else
		exe = NULL;
	return (exe);
}

static void	assign_av(t_exe *exe, int argc, t_list *l_token)
{
	char	**path_my;
	char	**path;

	exe->cmd.av[argc] = ((t_token *)l_token->content)->str;
	if (argc == 0)
	{
		path_my = calloc_erx(2, sizeof(char *));
		*path_my = ft_strdup("./builtin/bin");
		path = ft_split(getenv("PATH"), ':');
		exe->cmd.path = get_path(path, path_my,
				((t_token *)l_token->content)->str);
		free_path(path, path_my);
	}
}

static void	assign_redirect(t_exe *exe, t_meta type, char *value)
{
	if (type == RD_IN)
		exe->cmd.fd_rd[R] = open_fd(value, O_RDONLY, 0);
	else if (type == RD_IN_HRDC)
	{
		exe->cmd.fname_heredoc = ft_itoa_ulong_base((unsigned long)value,
				"0123456789ABCDEF");
		exe->cmd.fd_rd[R] = get_heredoc(exe->cmd.fname_heredoc, value);
	}
	else if (type == RD_OUT)
		exe->cmd.fd_rd[W] = open_fd(value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == RD_OUT_APND)
		exe->cmd.fd_rd[W] = open_fd(value, O_WRONLY | O_CREAT | O_APPEND, 0644);
}

static void	apply_redirect(t_exe *exe, t_exe *tmp)
{
	if (!exe->cmd.fd_rd[R] && tmp->cmd.fd_rd[R])
	{
		exe->cmd.fd_rd[R] = tmp->cmd.fd_rd[R];
		if (tmp->cmd.fname_heredoc)
			exe->cmd.fname_heredoc = tmp->cmd.fname_heredoc;
	}
	else if (tmp->cmd.fd_rd[R])
	{
		close_fd(tmp->cmd.fd_rd[R]);
		if (tmp->cmd.fname_heredoc)
			unlink(tmp->cmd.fname_heredoc);
	}
	if (!exe->cmd.fd_rd[W] && tmp->cmd.fd_rd[W])
		exe->cmd.fd_rd[W] = tmp->cmd.fd_rd[W];
	else if (tmp->cmd.fd_rd[W])
		close_fd(tmp->cmd.fd_rd[W]);
}
