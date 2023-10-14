/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:50:31 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 06:30:02 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// exit take the argument
// if no argument, take curnt exit_status
// and pipe doesn't terminate the shell // maybe use siguser?

#include <signal.h>
#include <stdlib.h>

#include "minishell.h"

static t_bool	compare_name(t_exe *exe, char *name);

void	execute_builtin(t_exe *exe, char **env)
{
	if (compare_name(exe, "pwd"))
		g_exit = pwd();
	else if (compare_name(exe, "exit"))
		if (kill(0, SIGTERM) == ERROR)
			exit_error("kill");
	// if (compare_name(exe, "cd"))
	// else if (compare_name(exe, "echo"))
	// else if (compare_name(exe, "env"))
	// else if (compare_name(exe, "exit"))
	// else if (compare_name(exe, "export"))
	// else if (compare_name(exe, "pwd"))
	// else if (comapre_name(exe, "unset"))
	(void)env;
	exit(g_exit);
}

static t_bool	compare_name(t_exe *exe, char *name)
{
	return (ft_strncmp(exe->cmd.path, name, ft_strlen(name) + 1) == MATCH);
}
