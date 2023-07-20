/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:43:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/21 05:13:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "pipex.h"

static t_cmd	*get_ary_cmd(char **path, t_uint cnt, char **av);
static char		**get_argv(char *input);
static char		*get_name(char **path, char *cmd);

void	init_cmd(t_data *input, int ac, char **av)
{
	input->cnt_cmd = ac - 3 - (input->heredoc == TRUE);
	input->cmd = get_ary_cmd(input->env_path, input->cnt_cmd,
			av + 2 + (input->heredoc == TRUE));
}

static t_cmd	*get_ary_cmd(char **path, t_uint cnt, char **av)
{
	t_cmd	*cmd;
	t_uint	idx;

	cmd = ft_calloc(cnt, sizeof(t_cmd));
	if (!cmd)
		exit_with_error("malloc");
	idx = 0;
	while (idx < cnt)
	{
		cmd[idx].av = get_argv(av[idx]);
		cmd[idx].name = get_name(path, ft_strjoin("/", *cmd[idx].av));
		idx++;
	}
	return (cmd);
}

static char	**get_argv(char *input)
{
	char	**av;

	av = ft_split(input, ' ');
	if (!av)
		exit_with_error("malloc");
	return (av);
}

static char	*get_name(char **path, char *cmd)
{
	static char	*name;

	if (!cmd)
		exit_with_error("malloc");
	if (*path)
	{
		name = ft_strjoin(*path, cmd);
		if (!name)
			exit_with_error("malloc");
		if (access(name, X_OK) != SUCCESS)
		{
			ft_free_set_null((void *)&name);
			get_name(path + 1, cmd);
		}
		else
			ft_free(cmd);
	}
	else
		ft_free(cmd);
	return (name);
}
