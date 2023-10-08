/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 02:02:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static t_process	*parse_token(t_list *l_token);
static t_bool		is_redirect(t_meta type);
static void			open_fd_redirect(t_process *procs, t_meta type, char *name);
static char			*get_name(char **path, char *av_cmd);
static char			*find_name(char **path, char *av_cmd);

t_list				*pass_to_next_cmd(t_list *l_token);
t_bool				is_pipe_and_or(t_list *l_token);

t_btree	*get_command(t_list *l_token)
{
	t_process	*procs;
	t_token		*op_seq;

	if (is_prntsis(l_token))
	{
		btr_add_r(&exe, btr_new(l_token->content));
		btr_add_l();
	}
}

// t_list	*get_command(t_list *l_token)
// {
// 	t_process	*l_procs;

// 	l_procs = NULL;
// 	while (l_token)
// 	{
// 		ft_lstadd_back(&l_procs, ft_lstnew(parse_token(l_token)));
// 		l_token = pass_to_next_cmd(l_token);
// 	}
// 	return (l_procs);
// }

t_bool	is_prntsis(t_list *l_token)
{
	return (((t_token *)l_token->content)->type == PRNTSIS_OPN
		|| ((t_token *)l_token->content)->type == PRNTSIS_CLS);
}

t_list	*pass_to_next_cmd(t_list *l_token)
{
	if (!l_token)
		return (l_token);
	else if (is_pipe_and_or(l_token))
		return (l_token->next);
	else
		return (pass_to_next_cmd(l_token->next));
}

t_bool	is_pipe_and_or(t_list *l_token)
{
	t_meta	type;

	type = ((t_token *)l_token->content)->type;
	return (type == PIPE || type == AND || type == OR);
}

static t_process	*parse_token(t_list *l_token)
{
	static int	argc;
	t_token		*token;
	t_process	*procs;

	if (l_token)
		token = l_token->content;
	else
		token = NULL;
	if (!token || (token->type != NONE && !is_redirect(token->type)))
	{
		if (argc)
		{
			procs = ft_calloc(1, sizeof(t_process));
			procs->cmd.av = ft_calloc(argc, sizeof(char *));
		}
		else
			procs = NULL;
	}
	else
	{
		if (token->type == NONE)
		{
			argc++;
			procs = parse_token(l_token->next);
			procs->cmd.av[--argc] = token->str;
			if (argc == 0)
				procs->cmd.name = get_name(ft_split(getenv("PATH"), ':'),
						token->str);
		}
		else
		{
			procs = parse_token(l_token->next->next);
			open_fd_redirect(procs, token->type,
				((t_token *)l_token->next->content)->str);
		}
	}
	return (procs);
}

static t_bool	is_redirect(t_meta type)
{
	return (type == RD_IN || type == RD_OUT
		|| type == RD_IN_HRDC || type == RD_OUT_APND);
}

static void	open_fd_redirect(t_process *procs, t_meta type, char *value)
{
	if (type == RD_IN)
		procs->cmd.rd_in = open_fd(value, O_RDONLY, 0);
	else if (type == RD_IN_HRDC)
	{
		procs->cmd.file_heredoc = ft_itoa_ulong_base((unsigned long)value,
				"0123456789ABCDEF");
		procs->cmd.rd_in = get_heredoc(procs->cmd.file_heredoc, value);
	}
	else if (type == RD_OUT)
		procs->cmd.rd_out = open_fd(value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == RD_OUT_APND)
		procs->cmd.rd_out = open_fd(value, O_WRONLY | O_CREAT | O_APPEND, 0644);
}

static char	*get_name(char **path, char *av_cmd)
{
	char	*name;

	if (*av_cmd == '.' || ft_strchr(av_cmd, '/'))
	{
		if (access(av_cmd, X_OK) == SUCCESS)
			name = ft_strdup(av_cmd);
		else
		{
			perror("access");
			name = ft_strdup("null");
		}
	}
	else
		name = find_name(path, ft_strjoin("/", av_cmd));
	return (name);
}

static char	*find_name(char **path, char *av_cmd)
{
	static char	*name;

	if (*path)
	{
		name = ft_strjoin(*path, av_cmd);
		if (access(name, X_OK) != SUCCESS)
		{
			ft_free_set_null((void *)&name);
			find_name(path + 1, av_cmd);
		}
		else
			ft_free(av_cmd);
	}
	else
		ft_free(av_cmd);
	return (name);
}
