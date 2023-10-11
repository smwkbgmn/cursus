/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/11 17:25:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static t_exe	*init_exe(int argc);
static void		assign_av(t_exe *exe, int argc, t_list *l_token);
static void		assign_redirect(t_exe *exe, t_meta type, char *name);

// now the rest metacharacters are AND, OR, PIPE, REDIRECTION, PRNTSIS

t_exe	*get_command(t_list *l_token)
{
	static int	argc;
	t_exe		*exe;

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
			exe = get_command(l_token->next->next);
			assign_redirect(exe, ref_type(l_token),
				((t_token *)l_token->next->content)->str);
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
	char	**env_path;

	exe->cmd.av[argc] = ((t_token *)l_token->content)->str;
	if (argc == 0)
	{
		env_path = ft_split(getenv("PATH"), ':');
		exe->cmd.path = get_path(env_path, ((t_token *)l_token->content)->str);
		// free env_path
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

