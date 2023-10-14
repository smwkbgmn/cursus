/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:27:02 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/14 06:17:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_name(char **path, char *av_cmd);

char	*get_path(char **path, char **path_my, char *av_cmd)
{
	char	*name;

	if (*av_cmd == '.' || ft_strchr(av_cmd, '/'))
	{
		if (access(av_cmd, X_OK) == SUCCESS)
			name = try(ft_strdup(av_cmd));
		else
		{
			write_errmsg("minishell: ");
			perror("access");
			name = try(ft_strdup("err_cmd"));
		}
	}
	else if (is_builtin(av_cmd))
		name = try(ft_strdup(av_cmd));
	else
	{
		name = find_name(path_my, ft_strjoin("/", av_cmd));
		if (!name)
			name = find_name(path, ft_strjoin("/", av_cmd));
	}
	return (name);
}

t_bool	is_builtin(char *av)
{
	return (ft_strncmp(av, "pwd", 4) == MATCH
		|| ft_strncmp(av, "exit", 5) == MATCH);
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
