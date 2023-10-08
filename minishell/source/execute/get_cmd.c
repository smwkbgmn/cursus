/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 20:28:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static t_bool	is_redirect(t_meta type);
static void		open_fd_redirect(t_execute *exe, t_meta type, char *name);

t_execute	*get_command(t_list *l_token)
{
	static int	argc;
	t_token		*token;
	t_execute	*exe;

	if (l_token)
		token = l_token->content;
	else
		token = NULL;
	if (!token || (token->type != NONE && !is_redirect(token->type)))
	{
		if (argc)
		{
			exe = ft_calloc(1, sizeof(t_execute));
			exe->cmd.av = ft_calloc(argc + 1, sizeof(char *));
		}
		else
			exe = NULL;
	}
	else
	{
		if (token->type == NONE)
		{
			argc++;
			exe = get_command(l_token->next);
			exe->cmd.av[--argc] = token->str;
			if (argc == 0)
				exe->cmd.name = get_name(ft_split(getenv("PATH"), ':'),
						token->str);
		}
		else
		{
			exe = get_command(l_token->next->next);
			open_fd_redirect(exe, token->type,
				((t_token *)l_token->next->content)->str);
		}
	}
	return (exe);
}

static t_bool	is_redirect(t_meta type)
{
	return (type == RD_IN || type == RD_OUT
		|| type == RD_IN_HRDC || type == RD_OUT_APND);
}

static void	open_fd_redirect(t_execute *exe, t_meta type, char *value)
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

