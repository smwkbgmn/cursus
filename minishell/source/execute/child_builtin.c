/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:50:31 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 20:55:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// exit do take the argument
// if no argument, take curnt exit_status
// and pipe doesn't terminate the shell // maybe use siguser?

#include <signal.h>
#include <stdlib.h>

#include "minishell.h"

static t_bool	is_name(t_exe *exe, char *is_name);

void	execute_builtin(t_exe *exe, t_bool pipemode)
{
	if (is_name(exe, "cd"))
		bltin_cd(exe->cmd.av);
	else if (is_name(exe, "echo"))
		bltin_echo(exe->cmd.av);
	else if (is_name(exe, "env"))
		bltin_env();
	else if (is_name(exe, "exit"))
		bltin_exit(exe->cmd.av);
	else if (is_name(exe, "export"))
		bltin_export(exe->cmd.av);
	else if (is_name(exe, "pwd"))
		bltin_pwd();
	else if (is_name(exe, "unset"))
		bltin_unset(exe->cmd.av);
	if (pipemode)
		exit(g_exit);
}

static t_bool	is_name(t_exe *exe, char *is_name)
{
	return (ft_strncmp(exe->cmd.path, is_name,
			ft_strlen(is_name) + 1) == MATCH);
}

t_bool	is_builtin(char *path)
{
	if (path)
	{
		return (ft_strncmp(path, "cd", 3) == MATCH
			|| ft_strncmp(path, "echo", 5) == MATCH
			|| ft_strncmp(path, "env", 4) == MATCH
			|| ft_strncmp(path, "exit", 5) == MATCH
			|| ft_strncmp(path, "export", 7) == MATCH
			|| ft_strncmp(path, "pwd", 4) == MATCH
			|| ft_strncmp(path, "unset", 6) == MATCH);
	}
	else
		return (FALSE);
}
