/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/09 14:51:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static t_execute	*init_exe(int argc);
static void			assign_av(t_execute *exe, int argc, t_list *l_token);
static void			assign_redirect(t_execute *exe, t_meta type, char *name);

// now the rest metacharacters are AND, OR, PIPE, REDIRECTION, PRNTSIS

t_execute	*get_command(t_list *l_token)
{
	static int	argc;
	t_execute	*exe;

	if (!l_token || is_sequence(l_token) || is_prntsis(l_token))
		exe = init_exe(argc);
	else
	{
		if (((t_token *)l_token->content)->type == NONE)
		{
			argc++;
			exe = get_command(l_token->next);
			assign_av(exe, --argc, l_token);
		}
		else
		{
			exe = get_command(l_token->next->next);
			assign_redirect(exe, ((t_token *)l_token->content)->type,
				((t_token *)l_token->next->content)->str);
		}
	}
	return (exe);
}

static t_execute	*init_exe(int argc)
{
	t_execute	*exe;

	if (argc)
	{
		exe = ft_calloc(1, sizeof(t_execute));
		exe->cmd.av = ft_calloc(argc + 1, sizeof(char *));
	}
	else
		exe = NULL;
	return (exe);
}

static void	assign_av(t_execute *exe, int argc, t_list *l_token)
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

static void	assign_redirect(t_execute *exe, t_meta type, char *value)
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

