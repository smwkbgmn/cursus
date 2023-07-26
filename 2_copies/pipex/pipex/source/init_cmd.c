/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:43:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/23 03:23:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "pipex.h"

static t_cmd	*get_ary_cmd(char **path, t_uint cnt, char **av);
static char		**get_argv(char *input);
static char		*get_name(char **path, char *cmd);
static char		*find_name(char **path, char *av_cmd);

void	init_cmd(t_data *input, int ac, char **av)
{
	input->cnt_cmd = ac - 3 - (input->heredoc == TRUE);
	input->cmd = get_ary_cmd(input->path, input->cnt_cmd,
			av + 2 + (input->heredoc == TRUE));
}

static t_cmd	*get_ary_cmd(char **path, t_uint cnt, char **av)
{
	t_cmd	*cmd;
	t_uint	idx;

	cmd = catcher(ft_calloc(cnt, sizeof(t_cmd)));
	idx = 0;
	while (idx < cnt)
	{
		cmd[idx].av = get_argv(av[idx]);
		cmd[idx].name = get_name(path, *cmd[idx].av);
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

static char	*get_name(char **path, char *av_cmd)
{
	char	*name;

	if (*av_cmd == '.' || ft_strchr(av_cmd, '/'))
	{
		if (access(av_cmd, X_OK) == SUCCESS)
			name = catcher(ft_strdup(av_cmd));
		else
		{
			perror("access");
			name = catcher(ft_strdup("null"));
		}
	}
	else
		name = find_name(path, catcher(ft_strjoin("/", av_cmd)));
	return (name);
}

// static char	*get_name(char **path, char *av_cmd)
// {
// 	char	*name;

// 	if (access(av_cmd, X_OK) == SUCCESS)
// 		name = catcher(ft_strdup(av_cmd));
// 	else
// 	{
// 		if (*av_cmd == '.' || ft_strchr(av_cmd, '/'))
// 		{
// 			perror("access");
// 			name = catcher(ft_strdup("null"));
// 		}
// 		else
// 			name = find_name(path, catcher(ft_strjoin("/", av_cmd)));
// 	}
// 	return (name);
// }

static char	*find_name(char **path, char *av_cmd)
{
	static char	*name;

	if (*path)
	{
		name = catcher(ft_strjoin(*path, av_cmd));
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
