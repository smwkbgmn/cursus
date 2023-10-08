/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:04:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/08 15:02:51 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>

#include "minishell.h"

static t_execute	*get_command(t_list *l_token);
static t_bool		is_redirect(t_meta type);
static void			open_fd_redirect(t_execute *exe, t_meta type, char *name);
static char			*get_name(char **path, char *av_cmd);
static char			*find_name(char **path, char *av_cmd);

static t_bool		is_prntsis(t_list *l_token);
// static t_list		*pass_to_next_cmd(t_list *l_token);
// static t_bool		is_pipe_and_or(t_list *l_token);

void	get_execute(t_list **l_exe, t_list *l_token)
{
	t_list		*token;
	t_meta		op_seq;
	t_execute	*exe;

	if (l_token)
	{
		token = l_token;
		if (is_prntsis(l_token))
		{	
			exe = ft_calloc(1, sizeof(t_execute));
			exe->op_seq = ((t_token *)token->content)->type;
			ft_lstadd_back(l_exe, ft_lstnew(exe));
			get_execute(l_exe, l_token->next);
			free(((t_token *)token->content)->str);
			ft_lstdelone(l_token, &free);
		}
		else
		{
			exe = get_command(l_token);
			while (token && ((t_token *)token->content)->type == NONE)
			{
				token = l_token->next;
				ft_lstdelone(l_token, &free);
			}
			if (token)
			{
				exe->op_seq = ((t_token *)token->content)->type;
				ft_lstadd_back(l_exe, ft_lstnew(exe));
				get_execute(l_exe, token);
			}
		}
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

static t_bool	is_prntsis(t_list *l_token)
{
	return (((t_token *)l_token->content)->type == PRNTSIS_OPN
		|| ((t_token *)l_token->content)->type == PRNTSIS_CLS);
}

// static t_list	*pass_to_next_cmd(t_list *l_token)
// {
// 	if (!l_token)
// 		return (l_token);
// 	else if (is_pipe_and_or(l_token))
// 		return (l_token->next);
// 	else
// 		return (pass_to_next_cmd(l_token->next));
// }

// static t_bool	is_pipe_and_or(t_list *l_token)
// {
// 	t_meta	type;

// 	type = ((t_token *)l_token->content)->type;
// 	return (type == PIPE || type == AND || type == OR);
// }

static t_execute	*get_command(t_list *l_token)
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
			exe->cmd.av = ft_calloc(argc, sizeof(char *));
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

// static t_process	*parse_token(t_list *l_token)
// {
// 	static int	argc;
// 	t_token		*token;
// 	t_process	*procs;

// 	if (l_token)
// 		token = l_token->content;
// 	else
// 		token = NULL;
// 	if (!token || (token->type != NONE && !is_redirect(token->type)))
// 	{
// 		if (argc)
// 		{
// 			procs = ft_calloc(1, sizeof(t_process));
// 			procs->cmd.av = ft_calloc(argc, sizeof(char *));
// 		}
// 		else
// 			procs = NULL;
// 	}
// 	else
// 	{
// 		if (token->type == NONE)
// 		{
// 			argc++;
// 			procs = parse_token(l_token->next);
// 			procs->cmd.av[--argc] = token->str;
// 			if (argc == 0)
// 				procs->cmd.name = get_name(ft_split(getenv("PATH"), ':'),
// 						token->str);
// 		}
// 		else
// 		{
// 			procs = parse_token(l_token->next->next);
// 			open_fd_redirect(procs, token->type,
// 				((t_token *)l_token->next->content)->str);
// 		}
// 	}
// 	return (procs);
// }

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
